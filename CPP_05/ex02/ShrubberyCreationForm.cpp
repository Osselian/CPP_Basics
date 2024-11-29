#include "ShrubberyCreationForm.hpp"
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
	std::ofstream  file(fileName.c_str());
	if (!file.is_open()) 
		throw TargetFileException("Can't open target file!");
	file << "shrauberry tree???" << std::endl;
}

ShrubberyCreationForm::TargetFileException::TargetFileException() throw()
{
	message = "Attempt to execute form that has not been signed!";
}

ShrubberyCreationForm::TargetFileException::TargetFileException(const string &msg) throw()
{
	message = msg;
}

ShrubberyCreationForm::TargetFileException::~TargetFileException() throw()
{
}

const char *ShrubberyCreationForm::TargetFileException::what() const throw()
{
	return message.c_str();
}