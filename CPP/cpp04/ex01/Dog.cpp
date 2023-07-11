
#include "Dog.hpp"

void	Dog::_init(void)
{
	this->setType("Dog");
	this->brain = new Brain();
}

Dog::Dog(void)
{
	this->_init();
	std::cout << "[Dog     ]: Default constructor called.\n";
}

Dog::~Dog(void)
{
	delete this->brain;
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
	std::cout << "[Dog     ]: A ferocious barking sound.\n";
}