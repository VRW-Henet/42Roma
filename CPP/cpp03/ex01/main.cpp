#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap	foe("foe");
	ClapTrap	kittenbot("kittenbot");
	ScavTrap	bunbot("bunbot");
	

	foe.initialize(10, 10, 0);
	std::cout << "\n";
	kittenbot.initialize(10, 10, 0);
	std::cout << "\n";
	bunbot.initialize(100, 50, 20);

	while (foe.getEnergy() || kittenbot.getEnergy()){
		foe.attack(kittenbot.getName());
		std::cout << "\n";
		kittenbot.takeDamage(foe.getAttack());
		std::cout << "\n";
		kittenbot.beRepaired(2);
		std::cout << "\n";
	}
    bunbot.guardGate();
	bunbot.attack(foe.getName());
	foe.takeDamage(bunbot.getAttack());
}