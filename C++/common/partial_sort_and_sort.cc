#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <string>


using std::vector;
using std::cout;
using std::endl;
using std::string;

int main() {
    srand(time(0));
    vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.emplace_back(rand() % 10);
    }
    auto print_func = [] (int i) {
        cout << i << endl;
    };
    cout << "----------------" << endl;
    std::for_each(vec.begin(), vec.end(), print_func);
    cout << "----------------" << endl;
    std::sort(vec.begin(), vec.begin() + 5); // 这个是在局部排序
    std::for_each(vec.begin(), vec.end(), print_func);
    std::partial_sort(vec.begin(), vec.begin() + 5, vec.end(), std::greater<int>()); // 这个是在全局排局部的序
    cout << "----------------" << endl;
    std::for_each(vec.begin(), vec.end(), print_func);
    cout << "----------------" << endl;

    return 0;
}