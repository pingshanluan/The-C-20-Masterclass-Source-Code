#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print() {
	cout << "\n";
}

template<typename T>
void Print(const T& a, const auto& ... args) {
	int sz = sizeof...(args);	// 3, 2, 1, 0

	cout << a;
	if (sz > 0)	// Don't print extra comma
		cout << ", ";

	Print(args...);
}

int main() {
	Print(1, 2, 3, 4);	// 1, 2, 3, 4
	Print("Mostafa", 'c', 5, 2.5);	// Mostafa, c, 5, 2.5

	return 0;
}
