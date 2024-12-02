#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}
Intern::Intern(const Intern &origin)
{
}
const Intern &Intern::operator=(const Intern &other)
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
	//throw exception
	return NULL;
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
		if (formName.find(keys[i]))
			return i;
		i++;
	}
	return -1;
}