#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	~ScavTrap();

	// member functions
	void initialize(int health, int energy, int attack);
	void attack(const std::string& target);
	void guardGate();

	int	getAttack();
};

#endif