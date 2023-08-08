#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request Form", 72, 45)
{
	std::cout << "Default costructor for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "Name costructor for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs)
{
	std::cout << "Copy costructor for RobotomyRequestForm called." << std::endl;
    *this = rhs;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this == &rhs )
	    return *this;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Default destructor for RobotomyRequestForm called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return std::string(this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	if ((rand() % 2 ) == 0)
		std::cout << this->_target << " has been robotomized!" << std::endl;
	else
		std::cout << this->_target << " robotomy failed "  << std::endl;
}