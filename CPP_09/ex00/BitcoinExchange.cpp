#include "BitcoinExchange.hpp"

#include <cctype>
#include <cstddef>
#include <ctime>
#include <exception>
#include <fstream>
#include <cerrno>
#include <cstdlib>
#include <iomanip>
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
		if (i++ == 0)
		{
			if (buf != "date,exchange_rate")
				throw InvalidFileFormatException();
			continue;
		}
		div_pos = buf.find(',', 0);
		if (div_pos == string::npos)
			throw InvalidFileFormatException("Data string has no divider!");
		string dtStr(buf, 0, div_pos);
		string curStr(buf, div_pos + 1);
		time_t date = getDate(dtStr); 
		float currency = getCurrency(curStr);
		_currencyMap[date] = currency;
	}
}

void BitcoinExchange:: printCurrency(string fileName)
{
	std::ifstream dataStream(fileName.c_str());
	if (!dataStream.is_open())
		throw InvalidFilePathException();

	string buf;
	size_t i = 0;
	while (std::getline(dataStream, buf))
	{
		try
		{
			if (checkHeader(&i, buf))
				continue;			
			size_t div_pos = getDivPos(buf);
			string dtStr(buf, 0, div_pos);
			string curStr(buf, div_pos + 1);
			time_t date = getDate(dtStr); 
			float currency = getValue(curStr);
			float dateCurrency = getDateCurrency(date);
			std::cout << std::fixed << std::setprecision(0) << dtStr << " => ";
			std::cout << currency << " = " << std::setprecision(2);
			std::cout << currency * dateCurrency << std::endl;
		}
		catch (std::exception & ex)
		{
			std::cout << ex.what() << std::endl;
			continue;
		}
	}
}

size_t BitcoinExchange::  getDivPos(string buf)
{
	size_t div_pos = buf.find('|', 0);
	if (div_pos == string::npos)
		throw InvalidFileFormatException("Invalid string format!\n");
	return div_pos;
}

bool BitcoinExchange:: checkHeader(size_t *i, string buf)
{
	if ((*i)++ == 0)
	{
		if (buf != "date | value")
			throw InvalidFileFormatException(
				"WARNING: File header may have incorrect format");
		return true;
	}
	return false;
}

float BitcoinExchange:: getDateCurrency(time_t date)
{
	float dateCurrency;
	std::map<time_t, float>::iterator it = _currencyMap.find(date);
	if (it != _currencyMap.end())
		return it->second;

	std::map<time_t, float>::iterator it_b = _currencyMap.begin();
	std::map<time_t, float>::iterator it_e = _currencyMap.end();
	while (it_b != it_e && difftime(date, it_b->first) > 0)
		it_b++;
	it_b--;
	if (it_b == it_e)
		throw InvalidFileFormatException("Data value out of range: too early!");
	dateCurrency = it_b->second;
	return dateCurrency;
}

float BitcoinExchange::getCurrency(string curStr)
{
	errno = 0;
	char *end;
	if (!std::isdigit(curStr[0]))
		throw InvalidFileFormatException();
	float res = std::strtof(curStr.c_str(), &end);
	if (errno == ERANGE || end == curStr || *end != '\0')
		throw InvalidFileFormatException();
	return res;
}

float BitcoinExchange::getValue(string curStr)
{
	errno = 0;
	char *end;
	if (!std::isdigit(curStr[0]) && curStr[0] != ' ')
		throw InvalidFileFormatException();
	float res = std::strtof(curStr.c_str(), &end);
	if (res == -0)
		res = 0;
	if (errno == ERANGE || end == curStr || *end != '\0' || res < 0.0 || res > 1000)
		throw InvalidFileFormatException();
	return res;
}

time_t BitcoinExchange::getDate(string dtStr)
{
	time_t raw;
	tm * date;
	char *next;

	time(&raw);
	date = localtime(&raw);

	next = setYear(dtStr.c_str(), date);
	next = setMonth(next, date);
	setDay(next, date);

	time_t utcTime =  std::mktime(date);
	return utcTime;
}

char *BitcoinExchange:: setYear(const char *start, tm * date)
{
	errno = 0;
	char *end;
	long year = std::strtol(start, &end, 10);
	if (errno == ERANGE || year < 1900)
		throw InvalidFileFormatException();
	date->tm_year = year;
	return end;
}

char *BitcoinExchange:: setMonth(char *divPtr, tm * date)
{
	errno = 0;
	if (*divPtr != '-')
		throw InvalidFileFormatException();
	char *end;
	long month = std::strtol(divPtr + 1, &end, 10);
	if (errno == ERANGE || month < 1 || month > 12)
		throw InvalidFileFormatException();
	date->tm_mon = month - 1;
	return end;
}

void BitcoinExchange:: setDay(char *divPtr, tm * date)
{
	errno = 0;
	if (*divPtr != '-')
		throw InvalidFileFormatException();
	long day = std::strtol(divPtr + 1, &divPtr, 10);
	if (checkConversionResult(day, date, divPtr))
		throw InvalidFileFormatException();
	date->tm_mday = day;
}

bool BitcoinExchange:: checkConversionResult(long day, tm *date, char *divPtr)
{
	int maxVal = _daysInMonths[date->tm_mon];
	if (date->tm_mon + 1 == 1 && isLeapYear(date->tm_year + 1900))
		maxVal = 29;
	string rem(divPtr);
	bool isErr =  errno == ERANGE;
	bool isFormatErr = rem.find_first_not_of(" ") != string::npos;
	bool isInvalid = day < 1 || day > maxVal;
	return isErr || isFormatErr  || isInvalid; 
}

bool BitcoinExchange::isLeapYear(long year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

BitcoinExchange::InvalidFileFormatException::InvalidFileFormatException() throw()
{
	_msg = "File's data has invalid format!";
}
BitcoinExchange::InvalidFileFormatException::InvalidFileFormatException(string message) throw()
{
	_msg = message;
}
const char *BitcoinExchange::InvalidFileFormatException::what() const throw()
{
	return _msg.c_str();
}

BitcoinExchange::InvalidFileFormatException::~InvalidFileFormatException() throw()
{
}

const char *BitcoinExchange::InvalidFilePathException::what() const throw()
{
	return "Can't open data file!";
}
