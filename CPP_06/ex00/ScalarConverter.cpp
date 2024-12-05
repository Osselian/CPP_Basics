#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdio>
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

int ScalarConverter::getType(const string &lit)
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

void ScalarConverter::handleChar(const string &lit)
{
	int i = static_cast<int>(lit[0]);
	float f = static_cast<double>(lit[0]);
	double d = static_cast<float>(lit[0]);
	std::cout << "type - char" << std::endl;
	printValues(lit[0], i, f, d);
}

void ScalarConverter::handleInt(const string &lit)
{
	std::cout << "type - int" << std::endl;
	int i = std::atoi(lit.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<double>(i);
	double d = static_cast<float>(i);
	printValues(c, i, f, d);
}

void ScalarConverter::handleFloat(const string &lit)
{
	std::cout << "type - float" << std::endl;
	float f = static_cast<float>(std::atof(lit.c_str()));
	double d = static_cast<double>(f);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	printValues(c, i, f, d);
}

void ScalarConverter::handleDouble(const string &lit)
{
	std::cout << "type - double" << std::endl;
	double d = std::atof(lit.c_str());
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	printValues(c, i, f, d);
}

int ScalarConverter::checkSpec(const string &lit)
{
	switch (getSpecType(lit)) 
	{
		case 0:
		case 1:
			handleInf( 0);
			return 1;
		case 2:
		case 3:
			handleInf( 1);
			return 1;
		case 4:
		case 5:
			handleNan();
			return 1;
		case 6:
			return 1;
	}
	return 0;
}

int ScalarConverter::getSpecType(const string &lit)
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

void ScalarConverter::handleInf(int sign)
{
	double d;
	float f;
	if (sign)
	{
		f = +INFINITY;
		d = std::numeric_limits<double>::infinity();
	}
	else
	{
		f = -INFINITY;
		d = -std::numeric_limits<double>::infinity();
	}
	std::cout << "character: impossible" << std::endl;
	std::cout << "integer: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(3);
	std::cout << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::handleNan()
{
	double d = std::numeric_limits<double>::quiet_NaN();
	float f = NAN;
	std::cout << "character: impossible" << std::endl;
	std::cout << "integer: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(3);
	std::cout << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printValues(char c, int i, float f, double d)
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

bool ScalarConverter::isCharacter(char c) 
{
	if (std::isalpha(c) || std::isspace(c) || std::ispunct(c))
		return true;
	return false;
}

const char *ScalarConverter::TypeNotFoundException::what() const throw()
{
	return "Type not found!";
}