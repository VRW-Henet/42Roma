#include "ClapTrap.hpp"

#include <iostream>

int main(void)
{
	ClapTrap	foe("foe");
	ClapTrap	kittenbot("kittenbot");

	foe.initialize(10, 10, 0);
	std::cout << "\n";
	kittenbot.initialize(10, 10, 0);
	std::cout << "\n";

	while (foe.getEnergy() || kittenbot.getEnergy()){
		foe.attack(kittenbot.getName());
		std::cout << "\n";
		kittenbot.takeDamage(foe.getAttack());
		std::cout << "\n";
		kittenbot.beRepaired(2);
		std::cout << "\n";
	}
}