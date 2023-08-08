
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	john("john", 1);
	Intern		intern;
	Form		*form;

	form = intern.makeForm("shrubbery creation", "cozy");

	john.SignForm(*form);
	john.executeForm(*form);
	delete form;

	form = intern.makeForm("robotomy request", "Bender");

	john.SignForm(*form);
	john.executeForm(*form);
	delete form;

	form = intern.makeForm("presidential pardon", "Jerry Smith");

	john.SignForm(*form);
	john.executeForm(*form);
	delete form;

	form = intern.makeForm("nothing", "Jerry Smith");
	delete form;
	return (0);
}
