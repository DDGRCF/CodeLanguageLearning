#include <algorithm>
#include <numeric>
#include <vector>
#include <stdio.h>
#include <iostream>

template<typename T>
// 这种他是不支持const int & 直接转化的

// 这几种要分清楚
//  | T& : param type | T
void f(T& param) {
	std::cout << param << std::endl;
}

// 可以通过函数偏特化来进行特殊声明
template<>
void f<const int>(const int & param) {
	std::cout << param << std::endl;
}

int main() {
	int x = 27;
	const int cx = x;
	const int & rx = x;

	f(x);
	f(cx);
	f(rx);

	// 因为偏特化的可能存在歧义，因此这里使用const int 显著标明
	// expr = 2;
	f<const int>(2);

	return 0;
}
