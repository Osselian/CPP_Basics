#ifndef SCALAR_CONVERTER
# define SCALAR_CONVERTER

#include <string>

typedef std::string string;

struct ConvertionData
{
	char character;
	int	integer;	
	float floating;
	double dFloat;
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &origin);
		const ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
		static bool isCharacter(char c);
		static string getType(const string &lit);

	public:
		static ConvertionData convert(const string &lit); 
};

#endif