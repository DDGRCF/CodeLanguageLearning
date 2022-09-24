#include <iostream>
#include <vector>
#include <utility>


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
    return c[0];
}

// c++14 终极表达式取值
template <typename Container, typename Index> 
decltype(auto) 
authAndAccess3(Container && c, Index i) {
    return std::forward<Container>(c)[i];
}

// c++11 终极表达式取值
template <typename Container, typename Index>
auto
authAndAccess4(Container && c, Index i) -> decltype(std::forward<Container>(c)[i])  {
    return std::forward<Container>(c)[i];
}



// decltype 对于表达式做一点变化，将产生巨大的影响
// 这里推导式是 int & ， 但是还是返回一个临时变量，还是不要用了，对于复杂表达式，总是得到一个左值引用
decltype(auto) f2() {
    int x = 0;
    return (x);
}

// decltype
// 这里推导是 int
decltype(auto) f3() {
    int x = 0;
    return x;
}

int main() {
    std::vector<int> c = {1, 2};
    int i = 0;
    authAndAccess(c, i);
    std::vector<int> b = {1, 2};

    authAndAccess4(b, 0) = 2;
    for (auto & item : b) {
        std::cout << item << std::endl;
    }

    std::cout << authAndAccess4(std::vector<int>{2, 2}, 0) << std::endl;

    return 0;
}