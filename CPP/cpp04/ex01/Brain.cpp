#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain constructor called\n";
}

Brain::~Brain(void)
{
	std::cout << "Destructor called. Brain destroyed\n";
}

Brain::Brain(const Brain &source)
{
	*this = source;
	std::cout << "Clone Brain constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &source)
{
	return (*this);
}