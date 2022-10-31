#include <stdio.h>
#include <vector>


template <typename T>
T test(std::vector<T>& vec) {
    printf("into vector...\n");
    T sum = 0;
    for (auto & v : vec) {
        sum += v;
    }
    return sum;
}

template <typename T>
T test(T (&vec)[4]) {
    printf("into array...\n");
    T sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += vec[i];
    }
    return sum;
}

int main() {
    std::vector<float> a = {0, 1, 2, 3};
    float b[4] = {0, 1, 2, 3};
    auto s1 = test(a);
    auto s2 = test(b);
    printf("s1: %f, s2: %f\n", s1, s2);
    return 0;
}