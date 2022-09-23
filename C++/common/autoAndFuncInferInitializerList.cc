#include <iostream>

template<typename T> 
void f(T param) {
    std::cout << "编译成功" << std::endl;
}

int main() {
    auto s = {11, 23, 9};  // 这里被推导成 std::initializer_list<int>
    for (auto & item : s) {
        std::cout << item << std::endl;
    }
    // f({11, 23, 9}); 将会被推导成 std::initializer_list<T> 编译不通过
    return 0;
}
