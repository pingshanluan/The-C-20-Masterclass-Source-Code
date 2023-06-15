#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto div_right(auto...args) {
	return (args / ...);
}

auto div_left(auto...args) {
	return (... / args);
}

int main() {
	// (((1/2)/3)/4) = 1/2/3/4 = 0.0416667
	cout<<div_left(1.0, 2.0, 3.0, 4.0)<<"\n";

	// 1 / (2 / (3/4) )= 0.375
	cout<<div_right(1.0, 2.0, 3.0, 4.0)<<"\n";

	cout<<div_left(1, 2, 3, 4)<<"\n";	// 0
	cout<<div_right(1, 2, 3, 4)<<"\n";	// RTE

	return 0;
}
