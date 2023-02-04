#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

void yuv2bgr(void* data, void **_bgr_data, size_t height, size_t width, const char* fmt) {
    size_t y_size = height * width;
    size_t u_size = height * width * 1/4;
    size_t v_size = height * width * 1/4;

    uint8_t* y_data = (uint8_t*)data;
    uint8_t* u_data = (uint8_t*)data + y_size;
    uint8_t* v_data = (uint8_t*)data + y_size + u_size;

    size_t b_size = height * width;
    size_t g_size = b_size;
    size_t r_size = b_size;
    size_t bgr_size = b_size + g_size + r_size;
    *_bgr_data = malloc(bgr_size);
    uint8_t* bgr_data = (uint8_t*)(*_bgr_data);

    if (strcmp(fmt, "yuv420p") == 0) {
        # pragma omp parallel for
        for (int i = 0; i < height; i++) {
            # pragma omp parallel for
            for (int j = 0; j < width; j++) {
                int y_col = j;
                int y_row = i;

                int u_col = j / 2; // 1
                int u_row = i / 2; // 1

                int v_col = j / 2; // 1
                int v_row = i / 2; // 1

                uint8_t y = *(y_data + y_row * width + y_col);
                uint8_t u = *(u_data + u_row * width/2 + u_col);
                uint8_t v = *(v_data + v_row * width/2 + v_col);

                uint8_t b = 1.164 * (y - 16) + 2.018 * (u - 128);
                uint8_t g = 1.164 * (y - 16) - 0.813 * (v - 128) - 0.391 * (u - 128);
                uint8_t r = 1.164 * (y - 16) + 1.596 * (v - 128);

                *(bgr_data + i * width * 3 + j * 3 + 0) = b;
                *(bgr_data + i * width * 3 + j * 3 + 1) = g;
                *(bgr_data + i * width * 3 + j * 3 + 2) = r;
            }
        }
    }
}

int main() {
    const char* video_path = "video_path";
    int height = 720;
    int width = 1280;

    size_t y_size = height * width;
    size_t u_size = height * width * 1 / 4;
    size_t v_size = height * width * 1 / 4;
    size_t yuv_size = y_size + u_size + v_size;    

    FILE* fp_yuv_video = fopen(video_path, "rb");

    uint8_t* data = (uint8_t*)malloc(yuv_size);
    int ret = 0;

    FILE* fp_y = fopen("output_1280x720_y.y", "wb");
    FILE* fp_u = fopen("output_1280x720_u.y", "wb");
    FILE* fp_v = fopen("output_1280x720_v.y", "wb");
    FILE* fp_yuv = fopen("output_1280x720.yuv", "wb");

    while ((ret = fread(data, 1, yuv_size, fp_yuv_video)) > 0) {
        fwrite(data, 1, yuv_size, fp_yuv);
        fwrite(data, 1, y_size, fp_y);
        fwrite(data + y_size, 1, u_size, fp_u);
        fwrite(data + y_size + u_size, 1, v_size, fp_v);
        break;
    }

    uint8_t* bgr_data = nullptr;
    yuv2bgr(data, (void **)&bgr_data, height, width, "yuv420p");
    cv::Mat img(height, width, CV_8UC3);
    memcpy(img.data, bgr_data, width * height * 3);
    cv::imwrite("output_1280x720.png", img);

    free(data);
    free(bgr_data);
    fclose(fp_y);
    fclose(fp_u);
    fclose(fp_v);
    fclose(fp_yuv_video);

    return ret;
}