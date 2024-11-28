#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberryCreationForm", 145, 137, "default_target") 
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
	: AForm("ShrubberryCreationForm", 145, 137, target) 
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &origin)
	: AForm(origin)
{
}

const ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() <= _gradeToExec)
		throw GradeToLowException("Unsufficient bureaucrat grade!");

	string fileName = _target + "_shrubbery"; //move to constructor
	std::ofstream  file(fileName);
	if (!file.is_open()) 
		throw TargetFileException("Can't open target file!");
	file << "shrauberry tree???" << std::endl;
}