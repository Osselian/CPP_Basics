#include "ScalarConverter.hpp"
#include "TypeNotFoundException.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &){}

const ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
	return *this;
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const std::string &lit)
{
	int res = checkSpec(lit);
	if (res)
		return ;
	switch (getType(lit)) 
	{
		case 0:
			handleChar(lit);
			break;
		case 1:
			handleInt(lit);
			break;
		case 2:
			handleFloat(lit);
			break;
		case 3:
			handleDouble(lit);
			break;
		case -1:
			throw TypeNotFoundException();
	}
}

int getType(const string &lit)
{
	bool isFloating = false;
	int length = lit.length();

	if (lit.length() == 1 && isCharacter(lit[0]))
		return 0;

	for (int i = 0; i < length; i++)
	{
		if (!std::isdigit(lit[i]))
		{
			if (i == 0)
			{
				if (lit[i] != '-')
					return -1;
				continue;
			} 
			else
			{
				if (lit[i] == '.' && !isFloating && i < length - 1 && std::isdigit(lit[i + 1]) && std::isdigit(lit[i - 1]))
					isFloating = true;
				else if (lit[i] == 'f' && i == length - 1 && std::isdigit(lit[i-1]))
					return 2;
				else
					return -1;
			}
		}
	}
	if (isFloating)
		return 3;
	return 1;
}

void handleChar(const string &lit)
{
	int i = static_cast<int>(lit[0]);
	float f = static_cast<double>(lit[0]);
	double d = static_cast<float>(lit[0]);
	std::cout << "type - char" << std::endl;
	printValues(lit[0], i, f, d);
}

void handleInt(const string &lit)
{
	std::cout << "type - int" << std::endl;
	int i = std::atoi(lit.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<double>(i);
	double d = static_cast<float>(i);
	printValues(c, i, f, d);
}

void handleFloat(const string &lit)
{
	std::cout << "type - float" << std::endl;
	float f = static_cast<float>(std::atof(lit.c_str()));
	double d = static_cast<double>(f);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	printValues(c, i, f, d);
}

void handleDouble(const string &lit)
{
	std::cout << "type - double" << std::endl;
	double d = std::atof(lit.c_str());
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	printValues(c, i, f, d);
}

int checkSpec(const string &lit)
{
	switch (getSpecType(lit)) 
	{
		case 0:
			handleInf(0, 0);
			return 1;
		case 1:
			handleInf( 1,0);
			return 1;
		case 2:
			handleInf(0, 1);
			return 1;
		case 3:
			handleInf( 1,1);
			return 1;
		case 4:
			handleNan(0);
			return 1;
		case 5:
			handleNan(1);
			return 1;
		case 6:
			return 1;
	}
	return 0;
}

int getSpecType(const string &lit)
{
	string specials[6] = 
	{
		"-inff",
		"-inf",
		"+inff",
		"+inf",
		"nanf",
		"nan"
	};

	for (int i = 0; i < 6; i++)
	{
		if (lit == specials[i])
			return i;
	}
	return -1;
}

void handleInf(int type, int sign)
{
	double d;
	float f;

	if (type)
	{
		if (sign)
			d = std::numeric_limits<double>::infinity();
		else
			d = -std::numeric_limits<double>::infinity();
		f = static_cast<float>(d);
	}
	else
	{
		if (sign)
			f = +INFINITY;
		else
			f = -INFINITY;
		d = static_cast<double>(f);
	}
	std::cout << "character: impossible" << std::endl;
	std::cout << "integer: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(3);
	std::cout << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void handleNan(int type)
{
	float f;
	double d;
	if (type)
	{
		d = std::numeric_limits<double>::quiet_NaN();
		f = static_cast<float>(d);
	}
	else
	{
		f = NAN;
		d = static_cast<double>(f);
	}
	std::cout << "character: impossible" << std::endl;
	std::cout << "integer: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(3);
	std::cout << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void printValues(char c, int i, float f, double d)
{
	if (std::isprint(c))
		std::cout << "character: " << c << std::endl;
	else
		std::cout << "character: not printable" << std::endl;
	std::cout << "integer: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(3);
	std::cout << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

bool isCharacter(char c) 
{
	if (std::isalpha(c) || std::isspace(c) || std::ispunct(c))
		return true;
	return false;
}