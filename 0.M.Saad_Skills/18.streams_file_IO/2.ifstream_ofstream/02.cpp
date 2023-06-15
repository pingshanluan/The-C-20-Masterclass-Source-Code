#include<iostream>
#include<fstream>	// for ifstream and ofstream
using namespace std;

int main() {
	//ifstream object works the same as std::cin
	ifstream fin("read_file.txt");

	if(fin.fail())
	{
		cout<<"Can't open the file\n";
		return 0;
	}
	int x, y;
	fin >> x >> y;
	//! don't forget to close file
	fin.close();
	
	//ifstream object works the same as std::cout
	ofstream fout("my_output.txt");

	if(fout.fail())
	{
		cout<<"Can't open the output file\n";
		return 0;
	}

	fout << x + y;			//<<std::flush		//flush the buffer if you can't see output in file
	//! don't forget to close file
	fout.close();



	// you can read from several files

	return 0;
}
