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
		bool checkConversionResult(long day, tm *date, char *divPtr);
		bool checkHeader(size_t * i, string buf);
		void fill_dayMonthsMap();
		float getCurrency(string curStr);
		time_t getDate(string dtStr);
		float getDateCurrency(time_t curStr);
		size_t getDivPos(string buf);
		float getValue(string curStr);
		bool isLeapYear(long year);
		void setDay(char *start, tm * date);
		char *setMonth(char *start, tm * date);
		char *setYear(const char *start, tm * date);
	public:
		BitcoinExchange();
		BitcoinExchange(string fileName);
		BitcoinExchange(const BitcoinExchange &origin);
		const BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		class InvalidFilePathException;
		class InvalidFileFormatException;
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
	private:
		string _msg;
	public:
		InvalidFileFormatException() throw();
		InvalidFileFormatException(string message) throw();
		virtual ~InvalidFileFormatException() throw();
		virtual const char *what() const throw();
};

 #endif