#include <iostream>
#include <optional>
using namespace std;

// optional: value might exist

int main() {
	//construction with value
	optional<int> x1 { 5 };
	optional x2 { 5 };
	auto x3 = make_optional(5);
	//constronctuion with no value
	optional<int> x4 { nullopt };	// No value
	optional<int> x5 { };			// No value
	optional<int> x5;			// No value

	//check if optional has value
	if (x3.has_value())
		//output value if optional has value
		cout << x3.value() << "\n";	// 5
		// *X3 deref to output value
		//cout << *x3 << "\n";

	//check if optional has value
	if (!x4)		// ! is overloaded to output bool, true=has_value, false=nullopt
		cout << "x4 is empty so far\n";	// printed

	//output value if optional has no value
	//cout << x5.value() << "\n";		// Exception: bad optional access
	cout << *x5 << "\n";				// Undefined behavior if not exists
	cout << x5.value_or(-1) << "\n";	// output -1 if has no value

	x1.reset();		// make nullopt
	x2 = nullopt;	// make nullopt
	x2 = 20;		// set new value

	return 0;
}
