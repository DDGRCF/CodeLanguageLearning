#include <iostream>
#include <vector>


// tricks: 如果要显示减小精度的 auot ep = static_cast<float>(calcEpsilon)，这样更直接
// std::vector<bool> 返回的 std::vector<bool>::reference 代理类，包含一个指针
std::vector<bool> features() {
    std::vector<bool> test{false, true, true, true};
    return test;
}

int main() {
    std::vector<bool> test_vec(5, 10);
    decltype(auto) tmp = test_vec[5];
    auto tmp2 = test_vec[5];
    std::cout << tmp << std::endl;
    std::cout << tmp2 << std::endl;
    auto tmp3 = features()[3];
    std::cout << (tmp3 ? "true" : "false") << std::endl; 
    return 0;
}