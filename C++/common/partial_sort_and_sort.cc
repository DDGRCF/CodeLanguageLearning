#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <string>
#include "utils.hpp"


using std::vector;
using std::cout;
using std::endl;
using std::string;

int main() {
    srand(time(0));
    vector<int> vec;
    size_t len = 10; size_t max = 10;

    cout << "sort--------------------------" << endl;
    vec = rand_vector(len, max);
    cout << join(vec, ", ") << endl;
    std::sort(vec.begin(), vec.begin() + 5); // 这个是在局部排序
    cout << join(vec, ", ") << endl;

    cout << "partial_sort--------------------------" << endl;
    vec = rand_vector(len, max);
    cout << join(vec, ", ") << endl;
    std::partial_sort(vec.begin(), vec.begin() + 5, vec.end(), std::greater<int>()); // 这个是在全局排局部的序
    cout << join(vec, ", ") << endl;

    cout << "stable_sort--------------------------" << endl;
    vec = rand_vector(len, max);
    cout << join(vec, ", ") << endl;
    std::stable_sort(vec.begin(), vec.end());
    cout << join(vec, ", ") << endl;


    return 0;
}