
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Creation Form", 145, 137)
{
	std::cout << "Default costructor for ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << "Name costructor for ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs)
{
	std::cout << "Copy costructor for ShrubberyCreationForm called." << std::endl;
    *this = rhs;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this == &rhs )
	    return *this;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default destructor for ShrubberyCreationForm called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return std::string(this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	std::ofstream file;
    file.open(_target + "_shrubbery");
    if (!file.is_open())
	{
        std::cout << "Can't open the " << _target << "_shrubbery file" << std::endl;
        return;
	}
	file << "                                   .         ;  " << std::endl;
    file << "      .              .              ;%     ;;   " << std::endl;
    file << "        ,           ,                :;%  %;   " << std::endl;
    file << "         :         ;                   :;%;'     .,   " << std::endl;
    file << ",.        %;     %;            ;        %;'    ,;" << std::endl;
    file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
    file << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    file << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    file << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    file << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
    file << "           `@%:.  :;%.         ;@@%;'   " << std::endl;
    file << "             `@%.  `;@%.      ;@@%;         " << std::endl;
    file << "               `@%%. `@%%    ;@@%;        " << std::endl;
    file << "                 ;@%. :@%%  %@@%;       " << std::endl;
    file << "                   %@bd%%%bd%%:;     " << std::endl;
    file << "                     #@%%%%%:;;" << std::endl;
    file << "                     %@@%%%::;" << std::endl;
    file << "                     %@@@%(o);  . '         " << std::endl;
    file << "                     %@@@o%;:(.,'         " << std::endl;
    file << "                 `.. %@@@o%::;         " << std::endl;
    file << "                    `)@@@o%::;         " << std::endl;
    file << "                     %@@(o)::;        " << std::endl;
    file << "                    .%@@@@%::;         " << std::endl;
    file << "                    ;%@@@@%::;.          " << std::endl;
    file << "                   ;%@@@@%%:;;;. " << std::endl;
    file << "               ...;%@@@@@%%:;;;;,.." << std::endl;
}