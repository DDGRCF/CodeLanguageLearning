#include <iostream>
#include <vector>


template<class C>
auto m_cbegin(const C & c) noexcept(noexcept(std::begin(c))) -> decltype(std::begin(c)) {
    return std::begin(c);
}


// 这里有一个关键点，就是decltype如果形参是const C & 类型，那么iterator推导出来将是const iterator类型，而不是引用
// 如果形参是 Container && c，那么c[i]推导出来将是T & 
template<class C>
auto m_cend(const C & c) noexcept(noexcept(std::begin(c))) -> decltype(std::end(c)) {
    return std::end(c);
}

int main() {
    std::vector<int> int_vec = {1, 2, 3};
    for (auto iterator = m_cbegin(int_vec); iterator != m_cend(int_vec); iterator++) {
        std::cout << *iterator << std::endl;
    }

    return 0;
}