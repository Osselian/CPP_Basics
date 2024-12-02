#ifndef INTERN
# define INTERN

#include "AForm.hpp"

class Intern
{
	private:
		int tryGetFormType(const string &formName) const;

	public:
		Intern();
		Intern(const Intern &);
		const Intern &operator=(const Intern &);
		~Intern();
		AForm *makeForm(const string &formName, const string &target) const;

	class FormTypeNotFoundException : public std::exception
	{
		private:
			std::string message;

		public:
			FormTypeNotFoundException() throw();
			FormTypeNotFoundException(const string &msg) throw();
			FormTypeNotFoundException(const FormTypeNotFoundException& origin) throw();
			~FormTypeNotFoundException() throw();
			virtual const char* what() const throw();
	};
};

#endif