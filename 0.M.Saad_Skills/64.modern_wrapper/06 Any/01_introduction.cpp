#include <iostream>
#include <any>
#include <map>
#include <string>
using namespace std;

//std::any provides flexbility, it can tore ANY type at runtime
//useful if the obj data type is not known, but must be copyable
//std::any is not templated
// narrow use cases, but good to know

int main() {


	//constuct with null
	any nothing1;		// has no value
	auto nothing2 = any{};

	//construct with value
	any a(12.5);	// not a template
	//assignment
	a = string("Hello!");
	a = 16;
	any b = a;	// copy

	//to access value, have to know the type and perform any_cast<>
	cout << any_cast<int>(a) << '\n';
	//if any_cast the wrong type, will get bad_any_cast exception
	// cout << any_cast<string>(a) << '\n';

	string* p1 = std::any_cast<string>(&a);	// nullptr
	any_cast<int&>(a) = 11;	// assign by reference

	a.reset();
	a.has_value();	// true or false;




	return 0;
}
