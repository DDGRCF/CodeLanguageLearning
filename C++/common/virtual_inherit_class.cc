#include <iostream>


#include <iostream>
using namespace std;
class A
{
    public:
    int i;
    void showa(){cout<<"i="<<i<<endl;}
};
class B:virtual public A      //此处采用虚继承
{
    public:
    int j;
};
class C:virtual public A      //此处采用虚继承
{
    public:
    int k;
};
 
 
// 解决二义性质问题，B同时继承了A，如果使用虚继承那么只有一个A虚基类
class D:public B,public C//调用析构函数时先调用虚基类的构造函数,然后挨个最后调用基类的析构函数,构造函数反过来
{
    public:
    int m;
};

int main()
{
    A a; B b; C c;
    a.i=1;
    a.showa();
    b.i=2;
    b.showa();
    c.i=3;
    c.showa();
    D d;
    d.i=4;
    d.showa();
    //cout << "Hello world!" << endl;
    return 0;
}
