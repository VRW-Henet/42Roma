
#ifndef SPRESIDENTIALPARDONFORM_HPP
# define SPRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string const			_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm&	operator=(PresidentialPardonForm const & rhs);
		~PresidentialPardonForm();
	
		std::string	getTarget() const;
		void		execute(Bureaucrat const & executor) const;

};

#endif