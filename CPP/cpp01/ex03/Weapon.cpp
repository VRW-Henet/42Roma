#include "Weapon.hpp"
#include <iostream>


Weapon::Weapon( std::string type ): type(type){
}

Weapon::~Weapon( void ){
}

bool		Weapon::setType( const std::string& newType )
{
	if (newType == "")
	{
		std::cout << "new type can't be empty string" << std::endl;
		return (false);
	}
	type = newType;
	return (true);
}

const std::string&	Weapon::getType(void) const{
	return (type);
}
