#include "Zombie.hpp"

Zombie::Zombie() : name("Nameless Zombie")
{
}
Zombie::Zombie( std::string name ): name(name)
{
}

void	Zombie::announce(void) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << name << ": I'm dying...again!" << std::endl;
}

std::string		Zombie::getname(void) const
{
	return (name);
}