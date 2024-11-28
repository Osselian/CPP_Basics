#include "AForm.hpp"

AForm::AForm() : 
	_name("Unspecified"), 
	_isSigned(false), 
	_gradeToSign(150), 
	_gradeToExec(150), 
	_target("default_target") 
{
}

AForm::AForm(const string &name, uint gradeToSign, uint gradeToExec, string target):
	_name(name), 
	_isSigned(false), 
	_gradeToSign(gradeToSign), 
	_gradeToExec(gradeToExec), 
	_target(target)
{
	if (gradeToSign == 0)
		throw GradeToHighException();
	if (gradeToSign > 150)
		throw GradeToLowException();
	if (gradeToExec == 0)
		throw GradeToHighException();
	if (gradeToExec > 150)
		throw GradeToLowException();
}

AForm::AForm(const AForm &origin): 
	_name(origin._name), 
	_isSigned(origin._isSigned), 
	_gradeToSign(origin._gradeToSign), 
	_gradeToExec(origin._gradeToExec),
	_target(origin._target)
{
	if (origin._gradeToSign == 0)
		throw GradeToHighException();
	if (origin._gradeToSign > 150)
		throw GradeToLowException();
	if (origin._gradeToExec == 0)
		throw GradeToHighException();
	if (origin._gradeToExec > 150)
		throw GradeToLowException();
}
const AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm()
{
}

const std::string AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _isSigned;
}

unsigned int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

unsigned int AForm::getGradeToExec() const
{
	return _gradeToExec;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		bureaucrat.signForm(_name);
	else
	{
		bureaucrat.signForm(_name, false, "his grade is too low!");
		throw GradeToLowException("Unsufficient bureaucrat grade!");
	}
}

AForm::GradeToHighException::GradeToHighException() throw()
{
	message = "Grade can't be higher than 1!";
}

AForm::GradeToHighException::GradeToHighException(const string &msg) throw()
{
	message = msg;
}

AForm::GradeToHighException::GradeToHighException(const GradeToHighException &origin) throw()
{
	message = origin.message;
}

AForm::GradeToHighException::~GradeToHighException() throw()
{
}

const char *AForm::GradeToHighException::what() const throw()
{
	return message.c_str();
}

AForm::GradeToLowException::GradeToLowException() throw()
{
	message = "Grade can't be lower than 150!";
}

AForm::GradeToLowException::GradeToLowException(const string &msg) throw()
{
	message = msg;
}

AForm::GradeToLowException::~GradeToLowException() throw()
{
}

const char *AForm::GradeToLowException::what() const throw()
{
	return message.c_str();
}

AForm::FormNotSignedException::FormNotSignedException() throw()
{
	message = "Attempt to execute form that has not been signed!";
}

AForm::FormNotSignedException::FormNotSignedException(const string &msg) throw()
{
	message = msg;
}

AForm::FormNotSignedException::~FormNotSignedException() throw()
{
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return message.c_str();
}