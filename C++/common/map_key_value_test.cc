#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, std::string> map{
        {"rcf", "one"}, {"wbk", "two"}
    };

    std::pair<std::string, std::string> item{"sbc", "three"};

    map.insert(item);

    // 这种1方法是拷贝，因为实际的map迭代的是std::pair<const std::string, std::string>
    std::cout << "Begin copy map iterator..." << std::endl;
    for (std::pair<std::string, std::string> item : map) {
        std::cout << "first: " <<item.first << std::endl; 
        std::cout << "second: " << item.second << std::endl;
    }

    // 这种方式不仅高效而且有效
    std::cout << "Begin no copy map iterator..." << std::endl;
    for (auto & item : map) {
        std::cout << "first: " << item.first << std::endl;
        std::cout << "second: " << item.second << std::endl;
    }

    return 0;
}