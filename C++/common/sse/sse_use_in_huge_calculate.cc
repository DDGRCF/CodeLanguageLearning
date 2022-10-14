#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <xmmintrin.h>

#include <vector>
#include <chrono>


template<typename T>
bool compare_eps(T t1, T t2, T eps) {
	return std::abs(t1 - t2) <= std::abs(eps) ? true : false;
}


// https://www.csie.ntu.edu.tw/~r89004/hive/sse/page_1.html
int main() {
	auto num_dim = 202400;
	std::vector<float> _tmp1(num_dim, 1);
	std::vector<float> _tmp2(num_dim, 2);
	std::vector<float> _tmp3(num_dim, 3);
	float _tmp4, _tmp5;
	// 对cpu进行预热
	for (int i = 0; i < num_dim; i++) {
		_tmp4 = _tmp3[i];
		_tmp5 = _tmp3[i];
		float _tmp6 = _tmp4 - _tmp5;
	}

	float* input1 = _tmp1.data();
	float* input2 = _tmp2.data();
	float output1[num_dim];
	float output2[num_dim];
	float output3[num_dim];

	// 第一部分计算
	auto part1_start_time = std::chrono::system_clock::now();
	for (int i = 0; i < num_dim; i++) {
		output1[i] = input1[i] + input2[i];
		output1[i] = output1[i] * input1[i];
		output1[i] = output1[i] + input1[i];
	}
	auto part1_end_time = std::chrono::system_clock::now();

	// 第二部分计算
	auto part2_start_time = std::chrono::system_clock::now();
	{
		float* _input1 = input1;
		float* _input2 = input2;
		float* _output2 = output2;
		for (int i = 0; i < num_dim / 4; i++, _input1+=4, _input2+=4, _output2 += 4) {
			__m128 data1 = _mm_load_ps(_input1);
			__m128 data2 = _mm_load_ps(_input2);
			__m128 data3 = _mm_add_ps(data1, data2);
			__m128 data4 = _mm_mul_ps(data3, data1);
			__m128 data5 = _mm_add_ps(data4, data1);
			_mm_store_ps(_output2, data5);
		}
	}
	auto part2_end_time = std::chrono::system_clock::now();

	// 第三部分计算
	auto part3_start_time = std::chrono::system_clock::now();
	{
		float* _input1 = input1;
		float* _input2 = input2;
		float* _output3 = output3;
		for (int i = 0; i < num_dim / 4; i++) {
			__m128 data1 = _mm_load_ps(_input1);  // 将128(4个float)位加载xmm0~xmm7，这些8位暂元器中
			__m128 data2 = _mm_load_ps(_input2);
			_mm_prefetch((const char *)(_input1 + 4), _MM_HINT_NTA); // 提前将input1中的数据从加载到cache L1 or L2 等地方
			_mm_prefetch((const char *)(_input2 + 4), _MM_HINT_NTA);
			__m128 data3 = _mm_add_ps(data1, data2); // + 
			__m128 data4 = _mm_mul_ps(data3, data1); // *
			__m128 data5 = _mm_add_ps(data4, data1); // +
			_mm_stream_ps(_output3, data5); // 把数据先存到主记忆体中?地方，主要由于这些数据不是马上用到，如果储存到cache L1中可能，浪费资源
			_output3 += 4;
			_input1 += 4;
			_input2 += 4;
		}
	}
	auto part3_end_time = std::chrono::system_clock::now();

	// 比较差距
	for (int i = 0; i < num_dim; i++) {
		assert(compare_eps(output1[i], output2[i], (float)0.001) && compare_eps(output1[i], output3[i], (float)0.001));
		printf("ori: %f, sse: %f, diff: %f\n", output1[i], output2[i], output1[i] - output2[i]);
	}

	// 打印时间
	printf("part1 cost: %ld, part2 cost: %ld, part3 cost: %ld\n", 
			std::chrono::duration_cast<std::chrono::microseconds>(part1_end_time - part1_start_time).count(),
			std::chrono::duration_cast<std::chrono::microseconds>(part2_end_time - part2_start_time).count(),
			std::chrono::duration_cast<std::chrono::microseconds>(part3_end_time - part3_start_time).count());
	
	return 0;
}
