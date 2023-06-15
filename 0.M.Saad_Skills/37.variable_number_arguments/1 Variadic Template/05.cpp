#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursion base case
int Sum() {
	return 0;
}

template<typename ... Args>
int Sum(int a, Args ... args) {
	return a + Sum(args...);
}

int main() {
	cout<<Sum(1, 2, 3, 4);

	// sum(1, 2, 3, 4)
	// 1 + sum(2, 3, 4)
	// 1 + 2 + sum(3, 4)
	// 1 + 2 + 3 + sum(4)
	// 1 + 2 + 3 + 4 + sum()
	// It is a RIGHT FOLD expansion
	// (1 + (2 + (3 + (4 + ()))))


	return 0;
}

