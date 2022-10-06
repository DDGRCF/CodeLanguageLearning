#include <iostream>
#include <memory>
#include <thread>


// 另外如果一个类没有拷贝构造函数，那么
// 执行了std::move 后就执行拷贝构造函数，而不是移动构造函数

class Investment {
    public:
        virtual void run() {
            std::cout << "run..." << std::endl;
        }
};
class Stock: public Investment {};
class Bond: public Investment {};
class RealEstate: public Investment {};

template<typename... Ts>
std::unique_ptr<Investment> 
make_investment(Ts&&... params) {
    std::cout << "create" << std::endl;
    return std::make_unique<Investment>(params...);
}


int main() {
    auto plnvestment = make_investment();
    std::thread threadOne([](std::unique_ptr<Investment> && investment){ // 移动构造函数是这样的A(A &&) 与 A & operator(A &&);
        std::thread::id thread_id = std::this_thread::get_id();
        std::cout << "thread-" << thread_id <<": run" << std::endl;
        investment->run();
    }, std::move(plnvestment));
    if (plnvestment == nullptr) {
        std::cout << "move to nullptr" << std::endl;
    }

    threadOne.join();
    // plnvestment->run();
    return 0;
}

