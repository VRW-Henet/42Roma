
#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Intern
{
	private:
		Form *Shrubbery( std::string FormTarget);
		Form *Robotomy( std::string FormTarget);
		Form *Presidential( std::string FormTarget);
	public:
	    Intern();
   		Intern( const Intern& src );
    	~Intern();
	
		Form *makeForm(std::string FormName, std::string FormTarget);
};

#endif