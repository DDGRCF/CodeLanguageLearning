#include <iostream>
#include <memory>

class TestClass {

};


int main() {
	auto del_func_unique = [](TestClass *tc) {
		std::cout << "delete test class unique ptr" << std::endl;
		delete tc;
	};

	auto del_func_shared = [](TestClass *tc) {
		std::cout << "delete test class shared ptr" << std::endl;
		delete tc;
	};

	std::unique_ptr<TestClass, decltype(del_func_unique)> upt(new TestClass{}, del_func_unique);
	std::shared_ptr<TestClass> ups(new TestClass{}, del_func_shared);
	std::cout << "Test" << std::endl;
	return 0;
}
