#ifndef SCALAR_CONVERTER
# define SCALAR_CONVERTER

#include <exception>
#include <string>

typedef std::string string;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &origin);
		const ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
		static bool isCharacter(char c);
		static int getType(const string &lit);
		static int getSpecType(const string &lit);
		static void handleChar(const string &lit);
		static void handleInt(const string &lit);
		static void handleFloat(const string &lit);
		static void handleDouble(const string &lit);
		static int checkSpec(const string &lit);
		static void printValues(char c, int i, float f, double d);
		static void handleInf(int sign);
		static void handleNan();

	public:
		static void convert(const string &lit); 

	class TypeNotFoundException : public std::exception
	{
          public:
            virtual const char *what() const throw();
    };
};

#endif