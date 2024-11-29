#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm", 72, 45, "default_target") 
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
	: AForm("RobotomyRequestForm", 72, 45, target) 
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &origin)
	: AForm(origin)
{
}

const RobotomyRequestForm &RobotomyRequestForm::operator=(
	const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() <= _gradeToExec)
		throw GradeToLowException("Unsufficient bureaucrat grade!");

	std::srand(time(0));
    int min = 0, max = 1;
    int is_success = min + std::rand() % (max - min + 1);
	std::cout << "*some drilling noises*\n";
	if (is_success) 
		std::cout << _target + " has been successfully robotomized!\n";
	else
		std::cout << "Robotomy for " + _target + " failed!\n";
}