#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename ... Args>
void Hello(int a, string name, Args ... args) {
	int sz = sizeof...(args);
	cout << a<<" "<<name<<" "<<sz << "\n";
}

int main() {
	Hello(1, "belal");				// 1 belal 0
	Hello(1, "belal", 2.5);			// 1 belal 1
	Hello(1, "belal", 2.5, "Me");	// 1 belal 2

	return 0;
}
