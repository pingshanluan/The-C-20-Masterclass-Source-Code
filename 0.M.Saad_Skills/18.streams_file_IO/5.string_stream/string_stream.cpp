#include<iostream>
#include<sstream>	

/*
A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin). To use stringstream, we need to include sstream header file. The stringstream class is extremely useful in parsing input. 
Basic methods are:
	clear()- To clear the stream.
	str()- To get and set string object whose content is present in the stream. 
	operator << Add a string to the stringstream object. 
	operator >> Read something from the stringstream object.
*/

int main() {
	std::string str = "Mostafa 23 years";

	//construct istringstream for dealing with input
	std::istringstream iss(str);

	std::string name;
	int age;

	//stringstream behave like cin, separation from whitespace
	iss>>name>>age;

	std::cout<<age<<"\n";

	//construct ostringstream for dealing with output
	std::ostringstream oss;

	oss<<"Mostafa ";
	oss<<50;
	oss<<" years old\n";

	std::cout<<oss.str();			//ostringstream::str returns the underlying string object

	return 0;

	return 0;
}
