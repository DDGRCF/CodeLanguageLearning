#include <iostream>

int main() {
    // 如何理解任何对象被析构后，移动源对象必须保持有效、可析构状态 TODO: 怎么理解 -_> https://www.zhihu.com/question/38846297/answer/78395323
    /* 可以将一个const引用(无论const &, 还是const &&) 都可以绑定到一个右值上去 */
    // int a = 2;
    // int &i = a * 2; // 错误：临时计算结果a * 2 是右值，不能绑定到左值引用
    // const int& ii = a * 2; // 正确：可以将一个const引用绑定到一个右值上
    // int &&r = a * 2; // 正确：std::move将左值a转换成了右值，能绑定到右值引用
    
    // int &i1 = 42; // 错误：42是字面常量，不能绑定到左值引用
    // int &&r1 = 42; // 正确：42是字面常量，能绑定到右值引用
    
    // int &i2 = std::move(a); // 错误：std::move将左值a转换成了右值，不能绑定到左值引用
    // int &&r2 = std::move(a); // 正确：std::move将左值a转换成了右值，能绑定到右值引用

    int *p = new int(42);
    int &&r = std::move(*p);
    std::cout << r << std::endl;
    r = 1;
    *p = 3; // 编译器不报错，也不会阻止修改源对象值，但不建议这么做
    // 因为move的字面含义就是移动后，原来的数值就会消失，但是由于很多类型都没有移动构造函数(也就是使用了std::move，产生的结果还是拷贝)
    std::cout << r << std::endl;
    std::cout << *p << std::endl;
    return 0;
}