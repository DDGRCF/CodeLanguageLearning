#include <iostream>
#include <string>

int main() {
	// 这两种定义是一样的
	char const * a = "22";
	const char * b = "22";

	// 指针指向不能变
	const char * const c = "22";
	
	std::cout << std::string(a) << std::endl; 
	std::cout << std::string(b) << std::endl; 
	std::cout << std::string(c) << std::endl; 
	return 0;
}
