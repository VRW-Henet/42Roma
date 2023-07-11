#include "Car.hpp"

void	WrongCat::_init(void)
{
	this->setType("WrongCat");
}

WrongCat::WrongCat(void)
{
	this->_init();
	std::cout << "[WrongCat     ]: Default WrongCat constructor called.\n";
}

WrongCat::~WrongCat(void)
{
	std::cout << "[WrongCat     ]: Destructor called.\n";
}

WrongCat::WrongCat(const WrongCat &source)
{
	*this = source;
	std::cout << "[WrongCat     ]: Clone constructor called.\n";
}

WrongCat &WrongCat::operator=(const WrongCat &source)
{
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "[WrongCat     ]: A kitten emitted a little meowing.\n";
}