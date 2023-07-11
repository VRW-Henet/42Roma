#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "ClapTrap constructor" << std::endl;
};

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor" << std::endl;
}

void	ClapTrap::initialize(int health, int energy, int attack)
{
	std::cout << this->_name << " setting health to " << health << std::endl;
	std::cout << this->_name << " setting energy to " << energy << std::endl;
	std::cout << this->_name << " setting attack to " << attack << std::endl;
	this->_health = health;
	this->_energy = energy;
	this->_attack = attack;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy < 1)
		return ;
	this->_energy--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing ";
	std::cout <<  this->_attack << " points of damage!" << std::endl;
	std::cout << "Current Energy " << this->_energy << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " recieve " << amount << " of damage" << std::endl;
	this->_health -= amount;
	std::cout << "Current Health " << this->_health << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy < 1)
		return ;
	_energy--;
	std::cout << "ClapTrap " << this->_name << " repaired " << amount << " of health" << std::endl;
	this->_health += amount;
	std::cout << "Current Health " << this->_health << std::endl;
	std::cout << "Current Energy " << this->_energy << std::endl;
}

std::string	ClapTrap::getName() { return this->_name; };

int	ClapTrap::getAttack() { return this->_attack; };

int	ClapTrap::getEnergy() { return this->_energy; };

int ClapTrap::getHealth() { return this->_health; };