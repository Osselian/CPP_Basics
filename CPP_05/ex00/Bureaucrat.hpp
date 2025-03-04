#ifndef BUREAUCRAT
# define BUREAUCRAT

#include <string>
class Bureaucrat
{
	private:
		const std::string _name;
		unsigned int _grade; 
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, unsigned int grade);
		Bureaucrat(const Bureaucrat &origin);
		const Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		const std::string getName() const;
		unsigned int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		

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