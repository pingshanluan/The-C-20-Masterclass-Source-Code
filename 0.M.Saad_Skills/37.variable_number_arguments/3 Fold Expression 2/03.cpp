#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// as template vardic
bool allVar() {
	return true;
}

template<typename T>
bool allVar(T t, auto ... args) {
	return t && allVar(args...);
}

////////////

// as fold expression

bool all(auto ... args) {
	return (... && args);
}

bool any(auto ... args) {
	return (... || args);
}

int main() {
	cout<<all(1, 1, 1)<<"\n";	// 1
	cout<<all(1, 0, 1)<<"\n";	// 0
	cout<<all()<<"\n";			// default 1
	cout<<any()<<"\n";			// default 0

	return 0;
}
