#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _currencyMap()
{
}

BitcoinExchange::BitcoinExchange(string fileName)
{
	_currencyMap = getMap(fileName);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &origin)
{
	_currencyMap = origin._currencyMap;
}

const BitcoinExchange &BitcoinExchange:: operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_currencyMap = other._currencyMap;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

std::map<string, uint> getMap(string fileName)
{

	std::ifstream dataStream(fileName);
	if (!dataStream.is_open())
		throw InvalidFilePathException();

	string buf;
	size_t div_pos;
	while (std::getline(dataStream, buf))
	{
		div_pos = buf.find(',', 0);
		if (div_pos == string::npos)
			throw InvalidFileFormatException();
		string date(buf, 0, div_pos);
		string currency(buf, div_pos);

	}

}