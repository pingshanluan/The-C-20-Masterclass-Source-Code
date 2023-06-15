#include<iostream>
#include<fstream>	// for ifstream and ofstream
using namespace std;

/*			ifstream, ofstream, fstream
The three classes that deal with file handling are:
	basic_ifstream
	basic_ofstream
	basic_fstream
ifstream, ofstream and fstream are "char" template specializations which means they are nothing but basic_ifstream<char>, basic_ofstream<char> and basic_fstream<char> i.e. they deal with reading and writing chars from a file.
	ifstream is input file stream which allows you to read the contents of a file.
	ofstream is output file stream which allows you to write contents to a file.
	fstream allows both reading from and writing to files by default. 
However, you can have an fstream behave like an ifstream or ofstream by passing in the ios::open_mode flag:
		Flag			Description
		ios::app		append, All write operations must occur at the end of the file
		ios::binary		Open in binary mode
		ios::in			Open for reading
		ios::out		Open for writing
		ios::trunc		Empty the contents of the file after opening
		ios::ate		Go to the end of the file after opening
	These flags are additive which means you can combine multiple flags using the bitwise OR | operator. If I want to open the file in binary mode and append, I can combine the flags as follows:
		ios::binary | ios::app
	ifstream always has the ios::in flag set and it cannot be removed. 
	ofstream always has the ios::out flag set and it cannot be removed. Any other flags added will be combined with ios::in for ifstream and ios::out for ofstream
	If you do not pass any flags to fstream, the default is ios::in | ios::out, so you can read from as well as write to the file. But if you specify a flag explicitly for fstream like ios::in, it will be opened only for reading, like an ifstream.
How to pass flags?
	You can do so in the constructor or when calling open()
	It is basically possible to never use ifstream and ofstream and always use fstream with the required flags. But it is prone to accidental errors while setting the flags. Hence, using ifstream you can be sure that writes will never occur and with ofstream only writes will take place.
*/

int main() {
	//reading and writing to a file simutaneously
	bool append = true;

	auto flags = ios::in | ios::out | ios::app;	// flags are additive, this means reading, writing, and appending 

	if (!append)
		flags = ios::in | ios::out | ios::trunc;	// overwrite, empty the contents of the file after opening

	string path = "names.txt";
	//use constructor
	fstream file_handler(path.c_str(), flags);		//std::string::c_str() returns a pointer to c style string (null-terminated)
	/*or use fstream::open
	std::fstream file_handler;
	file_handler.open("filename",flags)
	//flags can be: in, out, binary, ate, app, or trunc.
	*/
	if (file_handler.fail()) {
		cout << "Can't open the file\n";
		return 0;
	}
	string first, second;
	//reading
	file_handler >> first >> second;

	cout << first << " " << second << "\n";
	//writing
	file_handler.clear();	// if any internal errors, before writing
	file_handler << "\nibrahim\n";
	//close file
	file_handler.close();

	return 0;
}
