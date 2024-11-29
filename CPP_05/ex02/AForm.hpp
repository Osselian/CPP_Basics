#ifndef AFORM
# define AFORM

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
	protected:
		const std::string _name;
		bool _isSigned;
		const unsigned int _gradeToSign;
		const unsigned int _gradeToExec;
		const string _target;
	public:
		AForm();
		AForm(const std::string &name, uint gradeToSign, uint gradeToExec, string target);
		AForm(const AForm &origin);
		const AForm &operator=(const AForm &other);
		virtual ~AForm();
		const std::string getName() const;
		bool isSigned() const;
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExec() const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor)const = 0 ;

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

	class FormNotSignedException : public std::exception
	{
		private:
			std::string message;

		public:
			FormNotSignedException() throw();;
			FormNotSignedException(const string &msg) throw();
			FormNotSignedException(const FormNotSignedException& origin) throw();
			~FormNotSignedException() throw();;
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif