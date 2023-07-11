#include "Cat.hpp"

void	Cat::_init(void)
{
	this->setType("Cat");
}

Cat::Cat(void)
{
	this->_init();
	std::cout << "[Cat     ]: Default Cat constructor called.\n";
}

Cat::~Cat(void)
{
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
	std::cout << "[Cat     ]: Meow meow. :3 \n";
}