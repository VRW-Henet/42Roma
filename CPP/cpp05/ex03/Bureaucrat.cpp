#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat " << this->_name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
{
    std::cout << "Copy costructor for Bureaucrat called." << std::endl;
    *this = rhs;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor for Bureaucrat " << this->getName() << " called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs )
		_grade = rhs.getGrade();
	return *this;
}

std::string const Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
    std::cout << this->getName() << " Incremented his grade." << std::endl;
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
    std::cout << this->getName() << " Decremented his grade." << std::endl;
	this->_grade++;

}

std::ostream & operator<<(std::ostream &ost, Bureaucrat const & i)
{
	ost << i.getName() << ", bureaucrat grade " << i.getGrade();
	return ost;
}


void Bureaucrat::SignForm(Form &form)
{
    Bureaucrat::GradeTooHighException a;
    try
    {
        form.beSigned(*this);
        std::cout << form.get_name() << " has been signed by " << this->_name << std::endl;
        return ;
    }
    catch (Bureaucrat::GradeTooHighException &a){}
    catch (Bureaucrat::GradeTooLowException &a){}
    std::cout << form.get_name() << " can't be signed by " << this->_name << " because " << a.what() << std::endl;
}

void    Bureaucrat::executeForm( const Form &form ) const
{
    try
	{
        form.execute(*this);
    }
	catch (std::exception& e)
	{
        std::cout << _name << " couldn't execute " << form.get_name() << " because " << e.what() << std::endl;
    }
}