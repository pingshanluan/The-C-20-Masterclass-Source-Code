#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// We can pass other parameters,
// but make ...args the right most parameter
template<typename Function>
auto sum_square(Function operation, auto...args) {
	return (operation(args) + ... + 0);
}

int sq(int x) {
	return x * x;
}

int main() {
	int val = sum_square(sq, 1, 2, 3, 4);	// 30

	return 0;
}
