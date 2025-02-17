#include "RPN.hpp"
#include <cerrno>
#include <cstdlib>


RPN::RPN() {}

RPN::RPN(const RPN & origin)
{
	_nums = origin._nums;	
}

const RPN &RPN::operator=(const RPN & other)
{
	if (this != &other)
	{
		_nums = other._nums;
	}
	return *this;
}

RPN::~RPN()
{
}

long RPN::calculate(string dataRow)
{
	long result;
	size_t start = 0;
	size_t divPos = dataRow.find(' ');
	while (divPos != string::npos)
	{
		string val = dataRow.substr(start, divPos);
		if (val.empty())	
			continue;
		if (std::isdigit(val[0]))
			accumulateValue(val);
		else
			doOperation(val);
		dataRow = dataRow.erase(0, val.size() + 1);
		divPos = dataRow.find(' ');
	}
	if (dataRow.size() > 0)
	{
		doOperation(dataRow);
	}
	if (_nums.empty())
		throw InvalidExpressionException();
	result = _nums.top();
	_nums.pop();
	if (!_nums.empty())
		throw InvalidExpressionException();
	return result;
}

int RPN:: getFromStack()
{
	if (_nums.empty())
		throw InvalidExpressionException();
	int res = _nums.top();
	_nums.pop();
	return res;
}
void RPN:: doOperation(string val)
{
	int res;
	int second = getFromStack();
	int first = getFromStack();
	switch (val[0])
	{
	case '+':
		res = first + second;
		break;
	case '-':
		res = first - second;
		break;
	case '*':
		res = first * second;
		break;
	case '/':
		if (second == 0)
			throw NullDivisionExcepton();
		res = first / second;
		break;
	default:
		throw InvalidExpressionException();
	};
	_nums.push(res);
}

void RPN:: accumulateValue(string val)
{
	char *end;
	errno = 0;
	long num = strtol(val.c_str(), &end, 10);
	if (isNumValInvalid(num, val))
	{
		throw InvalidExpressionException();
	}
	_nums.push(static_cast<int>(num));
}

bool RPN:: isNumValInvalid(long num, string val)
{
	bool isError = errno == ERANGE;
	bool isConvertFails = num == 0L && val.find_first_not_of('0') != string::npos;
	bool isOutofRange =   num < 0 || num > 9;

	return isError || isConvertFails || isOutofRange;
}

const char *RPN::InvalidExpressionException:: what() const throw()
{
	return "Invalid expression!";
};

const char *RPN::NullDivisionExcepton:: what() const throw()
{
	return "Null division is restricted!";
};

RPN::InvalidOperationException::InvalidOperationException(char op) throw()
{
	_op = op;	
}

RPN::InvalidOperationException::~InvalidOperationException() throw()
{
}

const char *RPN::InvalidOperationException:: what() const throw()
{
	string msg = "Operation " + _op + " is restricted!";
	const char *res = msg.c_str();
	return res;
};