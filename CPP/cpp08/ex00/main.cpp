
#include "easyfind.hpp"
#include <list>
#include <vector>

int	main(int argc, char **argv)
{
	std::list<int>				arr;

	arr.push_back(2);
	arr.push_back(1);
	arr.push_back(4);
	arr.push_back(10);
	arr.push_back(5);
	arr.push_back(8);
	arr.push_back(7);
	arr.push_back(6);

    if (argc == 1)
    {
        try
        {
            std::cout << *(::easyfind(arr, 5)) << std::endl;
            std::cout << *(::easyfind(arr, 10)) << std::endl;
            std::cout << *(::easyfind(arr, -1)) << std::endl;
        }
        catch (ElementNotFound& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else if (argc == 2)
    {
        try
        {
            std::cout << *(::easyfind(arr, std::atoi(argv[1]))) << std::endl;
        }
        catch(ElementNotFound& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else
        std::cerr << "Bad Usage, use maximum 1 integer parameter" << std::endl;
}