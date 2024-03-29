
#include "AForm.hpp"

Form::Form() : _name("name"), _signed(0), _gradeToSign(50), _gradeToExecute(50)
{
}

Form::Form(std::string name, int const gradeToSign, int const gradeToExecute) : _name(name), _signed(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{

}

Form::Form(const Form &rhs) : _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute)
{
    std::cout <<  "Copy costructor for Form called." << std::endl;
    *this = rhs;
}

Form::~Form()
{
    std::cout << "Destructor for Form " << this->_name << " called." << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	if (this == &rhs )
	    return *this;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

void Form::beSigned(const Bureaucrat &bur)
{
    if (bur.getGrade() < 1)
        throw Form::GradeTooHighException();
	if (bur.getGrade() > 150)
		throw Form::GradeTooLowException();
    if (bur.getGrade() <= this->_gradeToSign)
        _signed = 1;
}

std::string Form::get_name() const
{
	return std::string(this->_name);
}

int Form::getGradeExec() const
{
    return (this->_gradeToExecute);
}

int Form::getGradeSign() const
{
    return (this->_gradeToSign);
}



bool Form::isSigned() const
{
	return (this->_signed);
}

std::ostream & operator<<(std::ostream &ost, Form const & i)
{
	ost << std::endl;
	ost << "Name: " << i.get_name() << std::endl;
	ost << "MinSign: " << i.getGradeSign() << std::endl;
	ost << "MinExec: " << i.getGradeExec() << std::endl;
	ost << "IsSigned: " << i.isSigned()<< std::endl;
	return ost;
}