#ifndef PRESIDENTIAL_PARDON_FORM
# define PRESIDENTIAL_PARDON_FORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &origin);
		const PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();
		void execute(Bureaucrat const &executor) const;
};

#endif