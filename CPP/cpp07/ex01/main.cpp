#include "iter.hpp"

int main()
{
	std::string strings[] = {"One", "Two", "Three", "Four"};

	std::cout << "Normal: " << std::endl;
	iter(strings, 4, temprint<std::string>);

	float floats[] = {1.23, 4.56, 7.89};
	std::cout << "Floats: " << std::endl;
	iter(floats, 3, temprint<float>);

	char chars[] = {'c', 'h', 'a', 'r'};
	std::cout << "String: " << std::endl;
	iter(chars, 4, temprint<char>);
}