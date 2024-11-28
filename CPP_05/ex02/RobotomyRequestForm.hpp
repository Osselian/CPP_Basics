#ifndef ROBOTOMY_REQUEST_FORM
# define ROBOTOMY_REQUEST_FORM

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(
			const std::string &name, unsigned int gradeToSign, unsigned int gradeToExec);
		RobotomyRequestForm(const RobotomyRequestForm &origin);
		const RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
		void execute(Bureaucrat const &executor) const;
};

#endif