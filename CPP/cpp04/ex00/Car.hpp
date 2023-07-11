#ifndef CAR_HPP
# define CAR_HPP

# include <iostream>
# include "Annimal.hpp"

class WrongCat : public WrongAnimal
{	
	public:
		void	_init();

		WrongCat();
		virtual ~WrongCat();

		WrongCat(WrongCat const &);

		WrongCat &operator=(const WrongCat &source);
		virtual void	makeSound(void) const;
};

#endif