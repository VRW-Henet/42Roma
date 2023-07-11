#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(std::string name);
	~FragTrap();

	// member functions
	void initialize(int health, int energy, int attack);
	void attack(const std::string& target);
	void highFivesGuys(void);

	int	getAttack();
};

#endif