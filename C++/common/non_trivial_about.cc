#include <iostream>
#include <memory.h>
#include <type_traits>

class TestClass {
    public: 
        int a;
        int b;
        void print() {
            std::cout << a << ", " << b << std::endl;
        }
};

class TestClass2: virtual public TestClass {
    public:
        int c;
};

class TestClass3: virtual public TestClass {
    public: 
        int d;
};

// 注意有非基础类型的比如string会导致非平凡
class TestClass4: public TestClass3, public TestClass2 {
    public: 
        int e;
};



// 非平凡构造函数详解 https://zhuanlan.zhihu.com/p/434531482
// 不是平凡狗构造函数最好不要使用memcpy和memove等构造函数
int main() {
    TestClass tc1{0, 0};    
    TestClass tc2{1, 1};
    // memmove(&tc2, &tc1, sizeof(tc1));
    // memmove在copy两个有重叠区域的内存时可以保证copy的正确，而memcopy就不行了 https://developer.aliyun.com/article/573048
    memcpy(&tc2, &tc1, sizeof(tc1));
    std::cout << tc1.a << ", " << tc1.b << std::endl;
    std::cout << tc2.a << ", " << tc2.b << std::endl;
    // 判断构造函数是否平凡
    std::cout << "trivially: " << std::is_trivially_copy_constructible<TestClass>::value << std::endl;

    TestClass4 tc3;
    TestClass4 tc4;
    tc3.c = 0; tc3.a = 0; tc3.b = 0;
    memcpy(&tc4, &tc3, sizeof(tc3));
    tc3.print();
    std::cout << "trivially: " << std::is_trivially_constructible<TestClass4>::value << std::endl;
    // std::cout << tc3.a << ", " << tc3.b << ", " << tc3.c <<std::endl;
    return 0;
}