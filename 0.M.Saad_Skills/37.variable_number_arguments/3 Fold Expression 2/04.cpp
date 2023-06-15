#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
void push_back_vec(vector<T>& v, auto... args) {
    (v.push_back(args), ...);
    // Expansion to right
    // (v.push_back(10), ...);
    // (v.push_back(10), (v.push_back(20), ...));
    // (v.push_back(10), (v.push_back(20), (v.push_back(30))));
    // SO overall: v.push_back(10), v.push_back(20), v.push_back(30)
}

template<typename T>
void PassPack(vector<T>& v, auto... args) {
	push_back_vec(v, args...);	// ... AFTER
}

int main() {
	vector<int> v;
	(v.push_back(6), (v.push_back(7), (v.push_back(6))));

	push_back_vec(v, 10, 20, 30);

	return 0;
}

int main1() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	v.push_back(3), v.push_back(4), v.push_back(5);

	(v.push_back(6), (v.push_back(7), (v.push_back(6))));

	// v = 1 2 3 4 5 6 7 6
	push_back_vec(v, 10, 20, 30);


	return 0;
}

