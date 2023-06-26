#include "zombieHorde.hpp"
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	unsigned int	N;
	std::string		name;
	Zombie			*horde;

	if (argc == 2)
	{
		N = 3;
		name = std::string(argv[1]);
		horde = zombieHorde(N, name);
		for (unsigned int i = 0; i < N; i++)
		{
			std::cout << "zombie n^" << i << " ";
			horde[i].announce();
		}
		if (N != 0)
			delete[] horde;
	}
	else
	{
		std::cout << "No brainzz" << std::endl;
	}
	std::cout << "END" << std::endl;
	return 0;
}
