#include <vector>
#include <string>
#include <iostream>

using namespace std;

class A {
public:
    A() = default;
    ~A() = default;
};

class ChildA: public A {

};

class B {
public:
    B() = default;
    ~B() = default;
};

class ChildB: public B {

};

class C {
public:
    virtual ~C()  {}
};
class ChildC: public C {
public:

};

int main() {
    // static_cast
    A a{}; ChildA a1{}; B b{}; ChildB b1{};
    B* p1 = (B*)(&a);
    // B* p2 = static_cast<B*>(&a); NOTE: 这个会在编译时进行检查，但不会进行运行时检查
    B* p3 = static_cast<B*>(&b);
    A* p4 = static_cast<A*>(&a1);

    // dynamic_cast
    // reinterpret_cast
    long i = 1e12;
    cout << i << endl;
    unsigned int* i1 = reinterpret_cast<unsigned int*>(&i); // 指针可以强制转化
    cout << *i1 << endl;
    // const_cast
    const int j = 2;
    cout << j << endl;
    // 不要这样用
    int& k = const_cast<int&>(j); // 不允许修改基础类型的const,可以运行但是很奇怪
    cout << &k << endl;
    k += 2;
    cout << &j << endl;
    cout << &k << endl;
    cout << j << " " << k <<endl;
    // string
    const string& m = "test";
    cout << m << endl;
    string& n = const_cast<string&>(m);
    n = "new test";
    cout << m << endl;
    // dynamic 只能使用指针
    C c{};
    A* p5 = dynamic_cast<A*>(&a1); // a1 和 p5同类型不需要多态
    ChildC* p6 = dynamic_cast<ChildC*>(&c); // 虚基类使用 c和p6不同类型，要有虚函数，多态
    if (p6 == nullptr) {
        cout << "empty" << endl;
    }

    return 0;
}

