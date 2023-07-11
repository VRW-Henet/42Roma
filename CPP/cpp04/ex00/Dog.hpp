#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
public:
	void	_init();

	Dog();
	virtual ~Dog();

	Dog(Dog const &);

	Dog &operator=(const Dog &source);

	virtual void	makeSound(void) const;

};

#endif