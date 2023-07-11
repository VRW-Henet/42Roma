#include "Bureaucrat.hpp"


int main()
{
    try
    {
		Bureaucrat bur("Highest", 1);
		std::cout << bur << std::endl;

		bur.incrementGrade();
	}
    catch (Bureaucrat::GradeTooHighException &b)
    {
		std::cout << b.what() << std::endl;
    }

    try
    {
		Bureaucrat bur("Luigi", 15);
		std::cout << bur << std::endl;

		bur.incrementGrade();
	}
    catch (Bureaucrat::GradeTooHighException &a)
    {
		std::cout << a.what() << std::endl;
    }

    try
    {
        Bureaucrat burry("Lowest", 150);
        std::cout << burry << std::endl;
		burry.decrementGrade();
    }
    catch (Bureaucrat::GradeTooLowException &c)
    {
		std::cout << c.what() << std::endl;
    }

	return 0;
}