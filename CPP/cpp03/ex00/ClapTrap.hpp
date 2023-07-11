#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
private:
	std::string	_name;
	int			_health;
	int			_energy;
	int			_attack;
public:
	ClapTrap(std::string name);
	~ClapTrap();

	// member functions
	void initialize(int health, int energy, int attack);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string	getName();
	int	getAttack();
	int	getEnergy();
	int	getHealth();
};

#endif