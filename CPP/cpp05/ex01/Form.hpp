#ifndef FORM_HPP
#define FORM_HPP


#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
    private:
        std::string const   _name;
        bool                _signed; // verifica se è stato firmato e alla costruzione non lo è
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

std::ostream & operator<<(std::ostream &ost, Form const & i);


#endif