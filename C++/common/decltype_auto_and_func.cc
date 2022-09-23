#include <iostream>
#include <vector>


// std=c++11 编译不通过 14 以上才行
// template <typename Container1, typename Index> 
// auto authAndAccess(Container1 & c, Index i) {
//     return c[0];
// }

// std=c++11
template <typename Container1, typename Index>
auto authAndAccess(Container1 & c, Index i) -> decltype(c[0]) {
    return c[0];
}

// 在std=c++14中 一般地，使用authAndAccess2的auto 等同于
// void f(T param)， 也就是const int 和 const int & 进来都会被推导成 int 
// 但是有decltype后，就会直接把auto推导成它原来具有的属性，比如const int 推导成 const int, int & 推导成 int &
// 那样具有的属性是返回值可以是引用，你就可以直接给他赋值了

template <typename Container1, typename Index> 
decltype(auto) authAndAccess2(Container1 & c, Index i) {

}


int main() {
    std::vector<int> c = {1, 2};
    int i = 0;
    authAndAccess(c, i);

    return 0;
}