#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
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
	int type = tryGetFormType(formName);
	if (type >= 0)
	{
		switch (type) 
		{
			case 0:
				return new ShrubberyCreationForm(target);
			case 1:
				return new RobotomyRequestForm(target);
			case 2:
				return new PresidentialPardonForm(target);
		}
	}
	throw FormTypeNotFoundException();
}

int Intern::tryGetFormType(const string &formName) const
{
	std::string keys[3] = 
	{
		"shrubberry",
		"robotomy",
		"presidential"
	};
	
	for (int i = 0; i < 3; i++)
	{
		int pos = formName.find(keys[i]);
		if (pos != -1)
			return i;
	}
	return -1;
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