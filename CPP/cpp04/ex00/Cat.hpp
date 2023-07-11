
#ifndef Cat_HPP
# define Cat_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{	
public:
	void	_init();

	Cat();
	virtual ~Cat();

	Cat(Cat const &);

	Cat &operator=(const Cat &source);
	virtual void	makeSound(void) const;
};

#endif