#include <iostream>
#include <atomic>

int main() {
    std::atomic_int flag{0}; // 这种不可拷贝对象只能使用{}初始化
    return 0;
}