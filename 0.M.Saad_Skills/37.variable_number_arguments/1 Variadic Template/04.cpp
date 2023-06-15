#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int SumArr(int arr[], int len) {
	if (len == 0)
		return 0;
	return arr[len-1] + SumArr(arr, len-1);
}

int main() {
	int a[5] = {1, 2, 3, 4, 5};
	cout<<SumArr(a, 5);

	return 0;
}
