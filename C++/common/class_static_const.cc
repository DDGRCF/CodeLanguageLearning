#include <iostream>
#include <string>

// 不同于c98 只允许 const static int
// c11 基本思想是 允许非静态（non-static）数据成员在其声明处（在其所属类内部）进行初始化
// 整个类都恒定的量，使用枚举 enum { SIZE1 = 100, SIZE2 = 200}; // 枚举常量 或者 static const
class A
{
private:
    const int a = 0;                // 常对象成员，可以使用初始化列表或者类内初始化
    const std::string c = "test";
    int b;
    static int d;

public:
    // 构造函数
    A() : a(0) { };
    A(int x) : a(x) { };        // 初始化列表

    // const可用于对重载函数的区分
    int getValue();             // 普通成员函数
    int getValue() const;       // 常成员函数，不得修改类中的任何数据成员的值
    // static int getValue() {return 0;};   // 静态成员函数重载是没有意义的, 但是是可以重载，但是上面使用非静态成员重载是没有意义的
};

int A::d = 2;

int A::getValue() {
    return a;
}

int A::getValue() const {
    return b; // 访问非常量变量，但是不能够使用
}



int main() {
    A a{};
    a.getValue();
    return 0;
}