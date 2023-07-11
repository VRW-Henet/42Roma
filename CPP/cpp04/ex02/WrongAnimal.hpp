
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		virtual void	makeSound(void) const;

		void	setType(std::string);

		std::string getType(void) const;

		WrongAnimal();
		WrongAnimal(WrongAnimal const &);
		WrongAnimal &operator=(const WrongAnimal &source);
		
		virtual ~WrongAnimal();
};

#endif