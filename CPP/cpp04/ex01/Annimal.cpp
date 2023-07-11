#include "Annimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "[WrongAnimal  ]: Default constructor called.\n";
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "[WrongAnimal  ]: Destructor called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &source)
{
	*this = source;
	std::cout << "[WrongAnimal  ]: Clone constructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &source)
{
	return (*this);
}

void	WrongAnimal::setType(std::string type)
{
	this->type = type;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "[WrongAnimal  ]: Random Wronganimal sound.\n";
}