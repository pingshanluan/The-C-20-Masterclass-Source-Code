#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename...Args>
auto multiply_unary_right_fold(Args...args) {
	return (args * ...);
	// 1 * (2 * (3 * 4)))
}

template<typename...Args>
auto multiply_binary_right_fold(Args...args) {
	return (args * ... * 1);
	// 1 * (2 * (3 * (4 * 1)))
}

template<typename...Args>
auto multiply_unary_left_fold(Args...args) {
	return (... * args);
	// ((1 * 2) * 3) * 4
}

template<typename...Args>
auto multiply_binary_left_fold(Args...args) {
	return (1 * ... * args);
	// (((1*1) * 2) * 3) * 4
}

int main() {
	cout<<multiply_unary_left_fold(1, 2, 3, 4); // 24



	return 1;
}
