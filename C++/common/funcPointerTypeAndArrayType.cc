#include <iostream>

template<typename T>
void f(T param) {

}

// 如果是引用则推导出来的数组类型, 统一退化成指针类型
// void f(T& param) {

// }
// array to pointer 退化准则
// method 1
void myFunc(const char param[]) {
    std::cout << "array" << std::endl;
}

// method 与上面是相同的
// void myFunc(const char* param) {
//     std::cout << "pointer" << std::endl;
// }

template<typename T, std::size_t N> 
constexpr std::size_t arraySize(T (&)[N]) noexcept {
    return N;
}

// 另外，连函数类型也会受到干扰
// void f1(T param) 和 void f2(T & param)，也会受到干扰，T&外，T都被退化成了void (*)）(xxx )的形式

int main() {
    const char name[] = "PJ Take";
    auto size = arraySize(name);
    std::cout << size << std::endl;
    myFunc(name);

    return 0;
}