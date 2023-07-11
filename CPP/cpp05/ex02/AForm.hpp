#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

class Bureaucrat;

class Form
{
    private:
        std::string const   _name;
        bool                _signed; 
        int const           _gradeToSign;
        int const           _gradeToExecute;

    public:
        Form();
        Form(std::string name, int const gradeToSign, int const gradeToExecute);
        Form(const Form &rhs);
        virtual ~Form();
        Form &operator=(const Form &rhs);

		std::string			get_name() const;
        int					getGradeExec() const;
        int                 getGradeSign() const;
        void                beSigned(const Bureaucrat& bur);
		bool				isSigned() const;
	 	virtual void        execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException: public std::exception { public: virtual const char* what() const throw() { return "Grade Too High"; }};

	class GradeTooLowException: public std::exception { public: virtual const char* what() const throw() { return "Grade Too Low"; }};
};

std::ostream & operator<<(std::ostream &ost, Form const & i);


#endif