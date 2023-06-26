#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie
{
private:
	std::string	name;
public:
	void	announce( void );
	void	setName( std::string name);
			Zombie();
			Zombie( std::string name );
			~Zombie();
};

#endif