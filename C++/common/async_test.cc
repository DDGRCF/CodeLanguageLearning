#include <future>
#include <unistd.h>
#include <iostream>

void func1() {
    for (int i = 0; i < 10; i++) {
        sleep(1);
        std::cout << "finish func1" << std::endl;
    }
}

void func2() {
    for (int i = 0; i < 10; i++) {
        sleep(1);
        std::cout << "finish func2" << std::endl;
    }
}

// 这个在没有future.get情况居然是同步
int main() {
    auto future1 = std::async(std::launch::async, func1);
    auto future2 = std::async(std::launch::async, func2);
    future1.get();
    future2.get();
    sleep(2);
    std::cout << "finish main"  << std::endl;
    return 0;
}