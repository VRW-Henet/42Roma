#ifndef ZOMBIE_HPP
#define	ZOMBIE_HPP

# include <string>
# include <iostream>

class	Zombie{
	private:
		std::string	name;
	public:
		Zombie();
		Zombie(std::string name);
		void	announce( void ) const;
		std::string	getname(void) const;
		~Zombie(void);
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );
	
#endif