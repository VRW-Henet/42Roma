#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce( void )
{
	std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name)
{
	this->name.assign(name);
}

Zombie::Zombie( std::string name )
{
	this->name.assign(name);
}

Zombie::Zombie()
{
	this->name = std::string();
}

Zombie::~Zombie()
{
	std::cout << this->name << ": " << "killed" << std::endl;
}
