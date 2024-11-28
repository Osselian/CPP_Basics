#ifndef FORM
# define FORM

#include "Bureaucrat.hpp"
#include <string>
class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const unsigned int _gradeToSign;
		const unsigned int _gradeToExec;
	public:
		Form();
		Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExec);
		Form(const Form &origin);
		const Form &operator=(const Form &other);
		~Form();
		const std::string getName() const;
		bool isSigned() const;
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExec() const;
		void beSigned(const Bureaucrat &bureaucrat);

	class GradeToHighException : public std::exception
	{
		private:
			std::string message;

		public:
			GradeToHighException() throw();
			GradeToHighException(const string &msg) throw();
			GradeToHighException(const GradeToHighException& origin) throw();
			~GradeToHighException() throw();
			virtual const char* what() const throw();
	};

	class GradeToLowException : public std::exception
	{
		private:
			std::string message;

		public:
			GradeToLowException() throw();;
			GradeToLowException(const string &msg) throw();
			GradeToLowException(const GradeToLowException& origin) throw();
			~GradeToLowException() throw();;
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif