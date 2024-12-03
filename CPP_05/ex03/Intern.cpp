#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	_keys[0] = "shrubberry";
	_keys[1] = "robotomy";
	_keys[2] = "presidential";

	_funcs[0] = &Intern::makeShrub;
	_funcs[1] = &Intern::makeRobo;
	_funcs[2] = &Intern::makePardon;
}

Intern::Intern(const Intern &)
{
}
const Intern &Intern::operator=(const Intern &)
{
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const string &formName, const string &target) const
{
	for (int i = 0; i < 3; i++)
	{
		int pos = formName.find(_keys[i]);
		if (pos != -1)
			return (this->*_funcs[i])(target);
	}
	throw FormTypeNotFoundException();
}

AForm *Intern::makeShrub(const string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobo(const string &target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePardon(const string &target) const
{
	return new PresidentialPardonForm(target);
}

Intern::FormTypeNotFoundException::FormTypeNotFoundException() throw()
{
	message = "Form type not found!";
}

Intern::FormTypeNotFoundException::FormTypeNotFoundException(const string &msg) throw()
{
	message = msg;
}

Intern::FormTypeNotFoundException::FormTypeNotFoundException(const FormTypeNotFoundException &origin) throw()
{
	message = origin.message;
}

Intern::FormTypeNotFoundException::~FormTypeNotFoundException() throw()
{
}

const char *Intern::FormTypeNotFoundException::what() const throw()
{
	return message.c_str();
}