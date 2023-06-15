#include <iostream>
#include <optional>
using namespace std;
/*
A "wrapper class" is a de facto term meaning a class that "wraps around" a resource; 
i.e, wrapper manages resource that it wraps in. When people write a wrapper, then they are doing something like this:
class int_ptr_wrapper
{
public:
    # constructor:
	int_ptr_wrapper(int value = 0) :
    mInt(new int(value))
    {}

    ## note! needs copy-constructor and copy-assignment operator!
	#destructor to release resource automatically
    ~int_ptr_wrapper()
    {
        delete mInt;
    }

private:
    int* mInt;
};
This class manages ("wraps") a pointer to an int. All resources should be wrapped in some fashion, for cleanliness (no explicit clean up code or noise) and correctness (destructor is guaranteed to run; cannot forget to clean up, and safe with exceptions).

Note that I said it was missing a copy-constructor and copy-assignment operator. This is due to the Rule of Three. (See linked question for detailed explanation.) The simplest way to correctly implement this rule is with the copy-and-swap idiom, explained here.

Sometimes, it's not pragmatic to write wrapper class for resource clean-up, usually when the resource is unique or used once. (Or with transactional programming.) The solution to this is called scope guard, a way of writing clean-up code inside the function that needs it.
*/

pair<bool, double> divide1(double a, double b) {
	if (b != 0.0)
		return {true, a / b};
	return {false, 0};
}

int process(int val = -1, int *p = nullptr) {
	if (val == -1 && p == nullptr)
		return -1;	// flag for can't process
	// or return <int, bool> to indicate
	int ret = 0;

	if (val != -1)
		ret += 2 * val + 1;
	if (p != nullptr)
		ret += 3 + *p;
	return ret;
}

int main() {


	return 0;
}
