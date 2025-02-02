#ifndef BTC
# define BTC

#include <map>
#include <string>

typedef std::string string;
typedef unsigned int uint;

class BitcoinExchange
{
	private:
		std::map<string, uint> _currencyMap;
	public:
		BitcoinExchange();
		BitcoinExchange(string fileName);
		BitcoinExchange(const BitcoinExchange &origin);
		const BitcoinExchange &BitcoinExchange:: operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		std::map<string, uint> getMap(string fileName);
		void printCurrency(string fileName);

		class InvalidFilePathException;
		class InvalidFileFormatException;
};

class InvalidFilePathException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class InvalidFileFormatException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif