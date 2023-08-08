
#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: no parameters\n" << "Usage: <program> <literal>" << std::endl;
		return 1;
	}
	
	Converter a;
	a.convert(argv[1]);
}