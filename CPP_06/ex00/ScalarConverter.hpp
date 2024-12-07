#ifndef SCALAR_CONVERTER
# define SCALAR_CONVERTER

#include <string>

typedef std::string string;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &origin);
		const ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
	public:
		static void convert(const string &lit); 
};

bool isCharacter(char c);
int getType(const string &lit);
int getSpecType(const string &lit);
void handleChar(const string &lit);
void handleInt(const string &lit);
void handleFloat(const string &lit);
void handleDouble(const string &lit);
int checkSpec(const string &lit);
void printValues(char c, int i, float f, double d);
void handleInf(int type, int sign);
void handleNan(int type);

#endif