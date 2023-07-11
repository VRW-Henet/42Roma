
#include "Dog.hpp"

void	Dog::_init(void)
{
	this->setType("Dog");
}

Dog::Dog(void)
{
	this->_init();
	std::cout << "[Dog     ]: Default constructor called.\n";
}

Dog::~Dog(void)
{
	std::cout << "[Dog     ]: Destructor called.\n";
}

Dog::Dog(const Dog &source)
{
	*this = source;
	std::cout << "[Dog     ]: Clone constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &source)
{
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "[Dog     ]: Meh! meh! (it was a Chihuahua)\n";
}