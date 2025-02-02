#include "BitcoinExchange.hpp"

#include <cctype>
#include <cstddef>
#include <ctime>
#include <fstream>
#include <tuple>


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

std::map<time_t, uint> BitcoinExchange:: getMap(string fileName)
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
		string dtStr(buf, 0, div_pos);
		string currency(buf, div_pos);
		time_t date = tryGetDate(dtStr); 
	}

}

time_t BitcoinExchange::tryGetDate(string dtStr)
{
	tm date;
	size_t start = 0;
	for (uint i = 0; i < 2; i ++)
	{
		size_t end = dtStr.find('-', end);
		if (end == string::npos)
			throw InvalidFileFormatException();
		string dateConstr(dtStr, start, end);
		if (i == 0)
		{
			int year = std::atoi(dateConstr.c_str());
			if (year < 0)
				throw InvalidFileFormatException();
		}
	}
}

const char *BitcoinExchange::InvalidFileFormatException::what() const throw()
{
	return "File's data has invalid format!";
}

