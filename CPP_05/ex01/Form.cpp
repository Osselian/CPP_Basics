#include "Form.hpp"

Form::Form() : _name("Unspecified"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
}

Form::Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
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

Form::Form(const Form &origin): 
	_name(origin._name), 
	_isSigned(origin._isSigned), 
	_gradeToSign(origin._gradeToSign), 
	_gradeToExec(origin._gradeToExec)
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
const Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form()
{
}

const std::string Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _isSigned;
}

unsigned int Form::getGradeToSign() const
{
	return _gradeToSign;
}

unsigned int Form::getGradeToExec() const
{
	return _gradeToExec;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		bureaucrat.signForm(_name);
	else
	{
		bureaucrat.signForm(_name, false, "his grade is too low!");
		throw GradeToLowException("Unsufficient bureaucrat grade!");
	}
}

Form::GradeToHighException::GradeToHighException() throw()
{
	message = "Grade can't be higher than 1!";
}

Form::GradeToHighException::GradeToHighException(const string &msg) throw()
{
	message = msg;
}

Form::GradeToHighException::GradeToHighException(const GradeToHighException &origin) throw()
{
	message = origin.message;
}

Form::GradeToHighException::~GradeToHighException() throw()
{
}

const char *Form::GradeToHighException::what() const throw()
{
	return message.c_str();
}

Form::GradeToLowException::GradeToLowException() throw()
{
	message = "Grade can't be lower than 150!";
}

Form::GradeToLowException::GradeToLowException(const string &msg) throw()
{
	message = msg;
}

Form::GradeToLowException::~GradeToLowException() throw()
{
}

const char *Form::GradeToLowException::what() const throw()
{
	return message.c_str();
}