#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
# include <string>

class	HumanB{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB(std::string name);
		~HumanB( void );

		bool	setWeapon( Weapon& newWeapon );
		Weapon&	getWeapon( void ) const;
		void	attack(void) const;
};

#endif