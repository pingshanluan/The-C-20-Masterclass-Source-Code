#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template<typename T>
T Sum() {
	return 0;
}

template<typename T, typename ... Args>
T Sum(T a, Args ... args) {
	// a is first number, and remaining in args
	return a + Sum<T>(args...);
}

int main() {
	cout<<Sum(1, 2, 3, 4)<<"\n";
	cout<<Sum(1.2, 2.3, 3.1, 4)<<"\n";	// 10.6
	cout<<Sum(1, 2.3, 3.1, 4.2)<<"\n";	// 10
	cout<<Sum<double>(1, 2.3, 3.1, 4.2)<<"\n";	// 10.6


	return 0;
}
