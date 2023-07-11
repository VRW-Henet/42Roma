#include "Form.hpp"

int	main()
{
    try {
        Bureaucrat bureaucrat("Cartesio",10);
        Form form("Piano", 50, 110);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    }
	catch (std::exception &e) 
	{
        std::cout << e.what() << std::endl;
    }
    return 0;
}