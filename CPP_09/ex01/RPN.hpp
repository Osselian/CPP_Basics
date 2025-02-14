#ifndef REVPOLNOT
# define REVPOLNOT

#include <stack>
#include <string>

typedef std::string string;

class RPN
{
	private:
		std::stack<int> _nums;
		void accumulateValue(string val);
		void doOperation(string val);
		int getFromStack();
		bool isNumValInvalid(long num, string val);
	public:
		RPN();
		RPN(const RPN & origin);
		const RPN &operator=(const RPN & other);
		~RPN();

		class InvalidExpressionException;	
		class NullDivisionExcepton;
		class InvalidOperationException;
		long calculate(string);
};

class RPN::InvalidExpressionException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class RPN::NullDivisionExcepton : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class RPN::InvalidOperationException : public std::exception
{
	private:
		string _op;
	public:
		InvalidOperationException(char op) throw();
		virtual ~InvalidOperationException() throw();
		virtual const char *what() const throw();
};
#endif