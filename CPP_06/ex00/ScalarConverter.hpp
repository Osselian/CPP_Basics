#ifndef SCALAR_CONVERTER
# define SCALAR_CONVERTER

#include <string>
struct ConvertionData
{
	char character;
	int	integer;	
	float floating;
	double dFloat;
};

class ScalarConverter
{
	static ConvertionData convert(const std::string lit); 

};

#endif