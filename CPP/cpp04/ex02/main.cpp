#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int	i = 0;
	int	max = 100;

	std::cout << std::endl;

	Animal *(animalList[100]);
	while (i < max)
	{
		if (i < max / 2)
			animalList[i] = new Dog();
		else
			animalList[i] = new Cat();
		i++;
	}

	std::cout << std::endl;
	
	i = 0;
	while (i < max)
		delete animalList[i++];

	std::cout << std::endl;

	return 0;
}