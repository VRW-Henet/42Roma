#include "Classes.hpp"

Base::~Base() 
{

}

Base*	generate(void) //entropic creation! 
{
	int		i;

	srand((unsigned)time(NULL));
	i = rand() % 3;
	switch (i)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	A	c1;
	B	c2;
	C	c3;
	try
	{
		c1 = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::bad_cast& e) {}
	try
	{
		c2 = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::bad_cast& e) {}
	try
	{
		c3 = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::bad_cast& e) {}
}