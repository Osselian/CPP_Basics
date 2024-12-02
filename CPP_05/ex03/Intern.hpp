#ifndef INTERN
# define INTERN

#include "AForm.hpp"

class Intern
{
	private:
		int tryGetFormType(const string &formName) const;

	public:
		Intern();
		Intern(const Intern &origin);
		const Intern &operator=(const Intern &other);
		~Intern();
		AForm *makeForm(const string &formName, const string &target) const;
};

#endif