#include "BitcoinExchange.hpp"

#include <cctype>
#include <cstddef>
#include <ctime>
#include <exception>
#include <fstream>
#include <cerrno>
#include <cstdlib>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
	fill_dayMonthsMap();
}

BitcoinExchange::BitcoinExchange(string fileName)
{
	fill_dayMonthsMap();
	setMap(fileName);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &origin)
{
	_daysInMonths = origin._daysInMonths;
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

void BitcoinExchange:: fill_dayMonthsMap()
{
	_daysInMonths[0] =  31;
	_daysInMonths[1] =  28;
	_daysInMonths[2] =  31;
	_daysInMonths[3] =  30;
	_daysInMonths[4] =  31;
	_daysInMonths[5] =  30;
	_daysInMonths[6] =  31;
	_daysInMonths[7] =  31;
	_daysInMonths[8] =  30;
	_daysInMonths[9] =  31;
	_daysInMonths[10] =  30;
	_daysInMonths[11] =  31;

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
		div_pos = buf.find(',', 0);
		// std::cout << "LINE #" << i  << ": " << buf << ": div pos: " << div_pos << std::endl;
		if (div_pos == string::npos)
			throw InvalidFileFormatException();
		string dtStr(buf, 0, div_pos);
		string curStr(buf, div_pos + 1);
		if (i++ == 0)
		{
			if (dtStr != "date" || curStr != "exchange_rate")
				throw InvalidFileFormatException();
			continue;
		}
		time_t date = getDate(dtStr); 
		uint currency = getCurrency(curStr);
		_currencyMap[date] = currency;
	}
}

void BitcoinExchange:: printCurrency(string fileName)
{
	std::ifstream dataStream(fileName.c_str());
	if (!dataStream.is_open())
		throw InvalidFilePathException();

	string buf;
	size_t div_pos;
	size_t i = 0;
	while (std::getline(dataStream, buf))
	{
		div_pos = buf.find('|', 0);
		// std::cout << "LINE #" << i  << ": " << buf << ": div pos: " << div_pos << std::endl;
		if (div_pos == string::npos)
			throw InvalidFileFormatException();
		string dtStr(buf, 0, div_pos);
		string curStr(buf, div_pos + 1);
		if (i++ == 0)
		{
			if (dtStr != "date " || curStr != " value")
				throw InvalidFileFormatException();
			continue;
		}
		try
		{
			time_t date = getDate(dtStr); 
			uint currency = getValue(curStr);
		}
		catch (std::exception & ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}
}

float BitcoinExchange::getCurrency(string curStr)
{
	errno = 0;
	char *end;
	if (!std::isdigit(curStr[0]))
		throw InvalidFileFormatException();
	float res = std::strtof(curStr.c_str(), &end);
	// std::cout << "CUR: " << res << ", END: " << end << ", START: " << curStr << std::endl;
	if (errno == ERANGE || end == curStr || *end != '\0')
		throw InvalidFileFormatException();
	return res;
}

float BitcoinExchange::getValue(string curStr)
{
	errno = 0;
	char *end;
	if (!std::isdigit(curStr[0]))
		throw InvalidFileFormatException();
	float res = std::strtof(curStr.c_str(), &end);
	// std::cout << "CUR: " << res << ", END: " << end << ", START: " << curStr << std::endl;
	if (errno == ERANGE || end == curStr || *end != '\0' || res < 0 || res > 1000)
		throw InvalidFileFormatException();
	return res;
}

time_t BitcoinExchange::getDate(string dtStr)
{
	tm date;
	char *next;
	next = setYear(dtStr.c_str(), date);
	// std::cout << "REMAINS: " << next << std::endl;
	next = setMonth(next, date);
	// std::cout << "REMAINS: " << next << std::endl;
	setDay(next, date);

	// std::cout << "DONE!" << std::endl;
	return std::mktime(&date);
}

char *BitcoinExchange:: setYear(const char *start, tm & date)
{
	errno = 0;
	char *end;
	long year = std::strtol(start, &end, 10);
	// std::cout << "YEAR: " << year << std::endl;
	if (errno == ERANGE || year < 1900)
		throw InvalidFileFormatException();
	date.tm_year = year - 1900;
	return end;
}

char *BitcoinExchange:: setMonth(char *divPtr, tm & date)
{
	errno = 0;
	if (*divPtr != '-')
		throw InvalidFileFormatException();
	char *end;
	long month = std::strtol(divPtr + 1, &end, 10);
	// std::cout << "MON: " << month << std::endl;
	if (errno == ERANGE || month < 1 || month > 12)
		throw InvalidFileFormatException();
	date.tm_mon = month - 1;
	return end;
}

void BitcoinExchange:: setDay(char *divPtr, tm & date)
{
	errno = 0;
	if (*divPtr != '-')
		throw InvalidFileFormatException();
	long day = std::strtol(divPtr + 1, &divPtr, 10);
	std::cout << "DAY: " << day << std::endl;
	int maxVal = _daysInMonths[date.tm_mon];
	if (date.tm_mon + 1 == 1 && isLeapYear(date.tm_year + 1900))
		maxVal = 29;
	if (errno == ERANGE || *divPtr != '\0' || day < 1 || day > maxVal)
		throw InvalidFileFormatException();
	date.tm_mday = day;
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

