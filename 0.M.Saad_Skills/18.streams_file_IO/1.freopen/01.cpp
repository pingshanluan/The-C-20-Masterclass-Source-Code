#include<iostream>

//freopen can convert std::cin and std::cout from console operation to file read and write

int main()
{
	//put std::freopen in main(), one can convert any project 
	//from console read and write to file read and write
	std::freopen("read_file.txt", "rt", stdin);
    std::freopen("my_output.txt", "wt", stdout);

	std::string str1="test string 1";
	std::string str2="test string 2";
	//cin is parsed with any white space in the input file
	std::cin >> str1;
	std::cin >> str2;
	std::cout << str1 << str2 << std::endl;
	return 0;
}
