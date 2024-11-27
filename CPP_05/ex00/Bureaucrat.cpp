#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Unspecified"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade == 0)
		throw GradeToHighException();
	if (grade > 150)
		throw GradeToLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &origin): _name(origin._name)
{
	if (origin._grade == 0)
		throw GradeToHighException();
	if (origin._grade > 150)
		throw GradeToLowException();
	_grade = origin._grade;
}
const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (other._grade == 0)
		throw GradeToHighException();
	if (other._grade > 150)
		throw GradeToLowException();
	_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 == 0)
		throw GradeToHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeToLowException();
	_grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() ;
	return os;
}

Bureaucrat::GradeToHighException::GradeToHighException() throw()
{
	message = "Grade can't be higher than 1!";
}

Bureaucrat::GradeToHighException::GradeToHighException(const GradeToHighException &origin) throw()
{
	message = origin.message;
}

Bureaucrat::GradeToHighException::~GradeToHighException() throw()
{
}

const char *Bureaucrat::GradeToHighException::what() const throw()
{
	return message.c_str();
}

Bureaucrat::GradeToLowException::GradeToLowException() throw()
{
	message = "Grade can't be lower than 150!";
}

Bureaucrat::GradeToLowException::~GradeToLowException() throw()
{
}

const char *Bureaucrat::GradeToLowException::what() const throw()
{
	return message.c_str();
}