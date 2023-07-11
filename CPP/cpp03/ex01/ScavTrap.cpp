#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor" << std::endl; 
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::initialize(int health, int energy, int attack)
{
	std::cout << this->_name << " setting health to " << health << std::endl;
	std::cout << this->_name << " setting energy to " << energy << std::endl;
	std::cout << this->_name << " setting attack to " << attack << std::endl;
	this->_health = health;
	this->_energy = energy;
	this->_attack = attack;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energy < 1)
		return ;
	this->_energy--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing ";
	std::cout <<  this->_attack << " points of damage!" << std::endl;
	std::cout << "Current Energy " << this->_energy << std::endl;
}

int	ScavTrap::getAttack() 
{
    return this->_attack; 
};