#ifndef BUREAUCRAT
# define BUREAUCRAT

#include <string>

typedef std::string string;
typedef unsigned int uint;

class Bureaucrat
{
	private:
		const string _name;
		unsigned int _grade; 
	public:
		Bureaucrat();
		Bureaucrat(const string &name, unsigned int grade);
		Bureaucrat(const Bureaucrat &origin);
		const Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		const string getName() const;
		unsigned int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(const string &form, bool success = true, const string &reason = "") const;
		

	class GradeToHighException : public std::exception
	{
		private:
			std::string message;

		public:
			GradeToHighException() throw();
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
			GradeToLowException(const GradeToLowException& origin) throw();
			~GradeToLowException() throw();;
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif