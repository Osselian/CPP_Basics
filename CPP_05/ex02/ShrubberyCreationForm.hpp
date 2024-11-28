#ifndef SHRUBBERY_CREATION_FORM
# define SHRUBBERY_CREATION_FORM

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &origin);
		const ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const &executor) const;

	class TargetFileException : public std::exception
	{
		private:
			std::string message;

		public:
			TargetFileException() throw();;
			TargetFileException(const string &msg) throw();
			TargetFileException(const TargetFileException& origin) throw();
			~TargetFileException() throw();;
			virtual const char* what() const throw();
	};
};

#endif