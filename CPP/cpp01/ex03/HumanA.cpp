#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon){
}

HumanA::~HumanA( void ){
}

void	HumanA::attack(void) const{
	std::cout << name << "attacks with their " << weapon.getType();
	std::cout << std::endl;
}

Weapon&	HumanA::getWeapon( void ) const{
	return (weapon);
}