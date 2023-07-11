

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const   _name;
        int                 _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &rhs);
        virtual ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat &rhs);

    std::string const   getName() const;
    int                 getGrade() const;
    void                incrementGrade();
    void                decrementGrade();
	void 				signForm(Form &form);
 /*
            EXCEPTION
 */
	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw() //vado a sovrascrivere la funzione what quando trovo throw
			{ 
				return "Grade Too High";
			}
	};

	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw() 
			{ 
				return "Grade Too Low";
			}
	};
};

std::ostream & operator<<(std::ostream &ost, Bureaucrat const & i);

#endif