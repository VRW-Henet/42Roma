#include "Cat.hpp"

void	Cat::_init(void)
{
	this->setType("Cat");
	this->brain = new Brain();
}

Cat::Cat(void)
{
	this->_init();
	std::cout << "[Cat     ]: Default Cat constructor called.\n";
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "[Cat     ]: Destructor called.\n";
}

Cat::Cat(const Cat &source)
{
	*this = source;
	std::cout << "[Cat     ]: Clone constructor called.\n";
}

Cat &Cat::operator=(const Cat &source)
{
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "[Cat     ]: A kitten emitted a little meowing.\n";
}