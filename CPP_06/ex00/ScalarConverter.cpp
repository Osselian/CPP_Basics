#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &){}

const ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
	return *this;
}

ScalarConverter::~ScalarConverter(){}

ConvertionData ScalarConverter::convert(const std::string &lit)
{
	ConvertionData data;

	string type = getType(lit);
	std::cout << type << std::endl;

	data.character = lit[0];
	return  data;
}

string ScalarConverter::getType(const string &lit)
{
	bool isFloating = false;
	int length = lit.length();

	if (lit.length() == 1 && isCharacter(lit[0]))
		return "char";

	for (int i = 0; i < length; i++)
	{
		if (!std::isdigit(lit[i]))
		{
			if (i == 0)
			{
				if (lit[i] != '-')
					return "INVALID";
				continue;
			} 
			else
			{
				if (lit[i] == '.' && !isFloating && i < length - 1 && std::isdigit(lit[i + 1]) && std::isdigit(lit[i - 1]))
					isFloating = true;
				else if (lit[i] == 'f' && i == length - 1)
					return "float";
				else
					return "INVALID";
			}
		}
	}
	if (isFloating)
		return "double";
	return "int";
}

bool ScalarConverter::isCharacter(char c) 
{
	if (std::isalpha(c) || std::isspace(c) || std::ispunct(c))
		return true;
	return false;
}

