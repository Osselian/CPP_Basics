#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("PresidentialPardonForm", 25, 5, "default_target") 
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
	: AForm("PresidentialPardonForm", 25, 5, target) 
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &origin)
	: AForm(origin)
{
}

const PresidentialPardonForm &PresidentialPardonForm::operator=(
	const PresidentialPardonForm &other)
{
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() <= _gradeToExec)
		throw GradeToLowException("Unsufficient bureaucrat grade!");

	std::cout << _target + " has been pardoned by Zaphod Beeblebrox!\n";
}