
#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{	
	private:
		Brain* brain;
	
	public:
		void	_init();

		Cat();
		virtual ~Cat();

		Cat(Cat const &);

		Cat &operator=(const Cat &source);
		
		virtual void	makeSound(void) const;
};

#endif