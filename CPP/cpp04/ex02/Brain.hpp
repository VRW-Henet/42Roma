
#ifndef Brain_HPP
# define Brain_HPP

# include <iostream>

class Brain
{
private:
	std::string ideas[100];
	
public:
	Brain();
	Brain(std::string);
	~Brain();

	Brain(Brain const &);

	Brain &operator=(const Brain &source);
};

#endif