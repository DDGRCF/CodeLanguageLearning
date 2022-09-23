#include <iostream>


template<typename T>
void f(T param) {
	std::cout << "before-----------" << std::endl;
	std::cout << param << std::endl;
	std::cout << "after-----------" << std::endl;
	param =  2;
	std::cout << param << std::endl;
}

int main() {
	int x = 27;
	const int cx = x;
	const int & rx = x;

	// T和param都是int, 不管有没有const 或者 引用
	f(x);
	f(cx);
	f(rx);

	std::cout << "x: " << x << std::endl;
	std::cout << "cx: " << cx << std::endl;
	std::cout << "rx: " << rx << std::endl;
	return 0;
}
