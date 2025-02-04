#include "BitcoinExchange.hpp"

#include <cstddef>
#include <ctime>
#include <fstream>
#include <cerrno>
#include <cstdlib>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(string fileName)
{
	setMap(fileName);
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

void BitcoinExchange:: setMap(string fileName)
{
	std::ifstream dataStream(fileName.c_str());
	if (!dataStream.is_open())
		throw InvalidFilePathException();

	string buf;
	size_t div_pos;
	size_t i = 0;
	while (std::getline(dataStream, buf))
	{
		if (i++ == 0)
			continue;
		div_pos = buf.find(',', 0);
		std::cout << "LINE #" << i  << ": " << buf << ": div pos: " << div_pos << std::endl;
		if (div_pos == string::npos)
			throw InvalidFileFormatException();
		string dtStr(buf, 0, div_pos);
		string curStr(buf, div_pos + 1);
		time_t date = tryGetDate(dtStr); 
		uint currency = tryGetCurrency(curStr);
		_currencyMap[date] = currency;
	}
}

float BitcoinExchange::tryGetCurrency(string curStr)
{
	char *end;
	errno = 0;
	float res = std::strtof(curStr.c_str(), &end);
	// std::cout << "CUR: " << res << ", END: " << end << ", START: " << curStr << std::endl;
	if (errno == ERANGE || end == curStr || *end != '\0')
		throw InvalidFileFormatException();
	return res;
}

time_t BitcoinExchange::tryGetDate(string dtStr)
{
	tm date;
	errno = 0;
	std::map<int, int> daysInMonths;
	daysInMonths[0] =  31;
	daysInMonths[1] =  28;
	daysInMonths[2] =  31;
	daysInMonths[3] =  30;
	daysInMonths[4] =  31;
	daysInMonths[5] =  30;
	daysInMonths[6] =  31;
	daysInMonths[7] =  31;
	daysInMonths[8] =  30;
	daysInMonths[9] =  31;
	daysInMonths[10] =  30;
	daysInMonths[11] =  31;

	// size_t start = 0;
	char *divPtr;
	long year = std::strtol(dtStr.c_str(), &divPtr, 10);
	// std::cout << "YEAR: " << year << std::endl;
	if (errno == ERANGE || year < 1900)
		throw InvalidFileFormatException();
	date.tm_year = year - 1900;

	if (*divPtr != '-')
		throw InvalidFileFormatException();
	long month = std::strtol(divPtr + 1, &divPtr, 10);
	// std::cout << "MON: " << month << std::endl;
	if (errno == ERANGE || month < 1 || month > 12)
		throw InvalidFileFormatException();
	date.tm_mon = month - 1;

	if (*divPtr != '-')
		throw InvalidFileFormatException();
	long day = std::strtol(divPtr + 1, &divPtr, 10);
	// std::cout << "DAY: " << day << std::endl;
	int maxVal = daysInMonths[month - 1];
	if (month == 1 && isLeapYear(year))
		maxVal = 29;
	if (errno == ERANGE || day < 1 || month > maxVal)
		throw InvalidFileFormatException();
	date.tm_mday = day;

	// std::cout << "DONE!" << std::endl;
	return std::mktime(&date);
}

bool BitcoinExchange::isLeapYear(long year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

const char *BitcoinExchange::InvalidFileFormatException::what() const throw()
{
	return "File's data has invalid format!";
}

const char *BitcoinExchange::InvalidFilePathException::what() const throw()
{
	return "Can't open data file!";
}

