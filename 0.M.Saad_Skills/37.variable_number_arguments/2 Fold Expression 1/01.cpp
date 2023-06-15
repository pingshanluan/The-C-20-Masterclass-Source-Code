#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename...Args>
auto sum_unary_right_fold(Args...args) {
	// (1,2,3,4) => sz = 4
	//int sz = sizeof...(args);

	return (args + ...);

	// Expansion (args + ...) for (1, 2, 3, 4)
	// (1 + ...)	=> replace ... with remaining (args + ...)
	// (1 + (2 + ...))
	// (1 + (2 + (3 + ...)))
	// (1 + (2 + (3 + 4)))
		// Close to Variadic Template right folding
		// arg0 + (arg1 + (arg2 + arg3))
	// Generation (1) => 1
	// Generation ()  => +    CE
}

template<typename...Args>
auto sum_binary_right_fold(Args...args) {
	return (args + ... + 0);
	// Compilation generation: (1, 2, 3, 4)
		// 1 + (2 + (3 + (4 + 0)))
	// Generation (1) => 1 + 0
	// Generation ()  => 0  OK
}

template<typename...Args>
auto sum_unary_left_fold(Args...args) {
	return (... + args);
	// Compilation generation: (1, 2, 3, 4)
	// ((1 + 2) + 3) + 4
}

template<typename...Args>
auto sum_binary_left_fold(Args...args) {
	return (0 + ... + args);
	// Compilation generation: (1, 2, 3, 4)
	// (((0+1) + 2) + 3) + 4
}

int main() {
	int xr = sum_unary_right_fold(1, 2, 3, 4);	// 10

	// CE: fold of empty expansion over operator+
	//int yr = sum_unary_right_fold();
	int yr = sum_binary_left_fold();	// 0

	int xl = sum_unary_left_fold(1, 2, 3, 4);	// 10

	// CE: fold of empty expansion over operator+
	//int yl = sum_unary_right_fold();
	int yl = sum_binary_left_fold();	// 0



	return 0;
}
