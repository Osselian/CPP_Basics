#ifndef PRESIDENTIAL_PARDON_FORM
# define PRESIDENTIAL_PARDON_FORM

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(
			const std::string &name, unsigned int gradeToSign, unsigned int gradeToExec);
		PresidentialPardonForm(const PresidentialPardonForm &origin);
		const PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();
		void execute(Bureaucrat const &executor) const;
};

#endif