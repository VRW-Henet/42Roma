#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap	foebot("foebot");
	ClapTrap	kittenbot("kittenbot");
	ScavTrap	bunbot("bunbot");
	FragTrap	pupbot("pupbot");

	foebot.initialize(10, 10, 0);
	std::cout << "\n";
	kittenbot.initialize(10, 10, 0);
	std::cout << "\n";
	bunbot.initialize(100, 50, 20);
	pupbot.initialize(100, 100, 30);

	foebot.attack(kittenbot.getName());
	std::cout << "\n";
	kittenbot.takeDamage(foebot.getAttack());
	std::cout << "\n";
	kittenbot.beRepaired(2);
	std::cout << "\n";

	bunbot.guardGate();		
	bunbot.attack(foebot.getName());
	foebot.takeDamage(bunbot.getAttack());
	std::cout << "\n";

	pupbot.highFivesGuys();
	std::cout << "\n";
}