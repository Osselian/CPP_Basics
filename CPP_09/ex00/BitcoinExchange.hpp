#ifndef BTC
# define BTC

#include <map>
#include <string>
#include <ctime>

typedef std::string string;
typedef unsigned int uint;

class BitcoinExchange
{
	private:
		std::map<time_t, float> _currencyMap;
		std::map<int, int> _daysInMonths;
		void fill_dayMonthsMap();
		time_t getDate(string dtStr);
		char *setYear(const char *start, tm & date);
		char *setMonth(char *start, tm & date);
		void setDay(char *start, tm & date);
		float getCurrency(string curStr);
		bool isLeapYear(long year);
	public:
		BitcoinExchange();
		BitcoinExchange(string fileName);
		BitcoinExchange(const BitcoinExchange &origin);
		const BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		class InvalidFilePathException;
		class InvalidFileFormatException;
		class ValueConverter;
		void setMap(string fileName);
		void printCurrency(string fileName);

};

class BitcoinExchange::InvalidFilePathException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class BitcoinExchange::InvalidFileFormatException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

 #endif