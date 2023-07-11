#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		virtual void	makeSound(void) const;

		void	setType(std::string);

		std::string getType(void) const;

		Animal();
		Animal(Animal const &);
		Animal &operator=(const Animal &source);
		
		virtual ~Animal() = 0;
};

#endif