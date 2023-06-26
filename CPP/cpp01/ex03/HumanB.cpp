#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): name(name){
}

HumanB::~HumanB( void ){
}

Weapon&	HumanB::getWeapon( void ) const{
	return (*weapon);
}

bool	HumanB::setWeapon( Weapon& newWeapon )
{
	if (newWeapon.getType() == "")
	{
		std::cerr << "New weapon can't be nothing" << std::endl;
		return (false);
	}
	weapon = &newWeapon;
	return (true);
}

void	HumanB::attack(void) const{
	std::cout << name << "attacks with their " << weapon->getType();
	std::cout << std::endl;
}