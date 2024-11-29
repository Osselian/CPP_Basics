#include "AForm.hpp"
#include <exception>
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Unspecified"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : _name(name)
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
	if (this != &other)
	{
		if (other._grade == 0)
			throw GradeToHighException();
		if (other._grade > 150)
			throw GradeToLowException();
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

unsigned int Bureaucrat::getGrade() const
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

void Bureaucrat::signForm(AForm  &form) const
{
	try
	{
		std::cout << _name + " sign " + form.getName() << std::endl;
		form.beSigned(*this);
		std::cout << _name + " successfully signed " + form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name + " couldn't sign " + form.getName() + " because " + e.what() << std::endl;
	}

}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		std::cout << _name + " execute " + form.getName() << std::endl;
		form.execute(*this);
		std::cout << _name + " executed " + form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
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

Bureaucrat::GradeToLowException::GradeToLowException(const GradeToLowException &origin) throw()
{
	message = origin.message;
}

Bureaucrat::GradeToLowException::~GradeToLowException() throw()
{
}

const char *Bureaucrat::GradeToLowException::what() const throw()
{
	return message.c_str();
}