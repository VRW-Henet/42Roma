#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "[Animal  ]: Default constructor called.\n";
}

Animal::~Animal(void)
{
	std::cout << "[Animal  ]: Destructor called.\n";
}

Animal::Animal(const Animal &source)
{
	*this = source;
	std::cout << "[Animal  ]: Clone constructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &source)
{
	return (*this);
}

void	Animal::setType(std::string type)
{
	this->type = type;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void	Animal::makeSound(void) const
{
	std::cout << "[Animal  ]: Random animal sound.\n";
}