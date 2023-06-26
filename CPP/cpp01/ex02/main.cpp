#include <string>
#include <iostream>

int	main(void){
	std::string	string = "HI THIS IS BRAIN";
	std::string &ref = string;
	std::string *ptr = &string;

	std::cout << "STRING memory address: " << &string << std::endl;
	std::cout << "PTR memory address: " << ptr << std::endl;
	std::cout << "REF memory address: " << &ref << std::endl;
	std::cout << std::endl;
	std::cout << "STRING value: " << string << std::endl;
	std::cout << "PTR value: " << *ptr << std::endl;
	std::cout << "REF value: " << ref << std::endl;
}