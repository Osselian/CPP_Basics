#include "BitcoinExchange.hpp"

#include <cstddef>
#include <ctime>
#include <fstream>

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
		string curStr(buf, div_pos);
		time_t date = tryGetDate(dtStr); 
		uint currency = tryGetCurrency(curStr);
	}

}

float BitcoinExchange::tryGetCurrency(string curStr)
{
	char *end;
	float res = std::strtof(curStr.c_str(), &end);
	if (res == 0.0F && (curStr[0] == '0' && curStr[1] == '.' && curStr[0] == '.'))
	{

	}
}

time_t BitcoinExchange::tryGetDate(string dtStr)
{
	tm date;
	std::map<int, int> daysInMonths =
	{
		{0, 31},
		{1, 28},
		{2, 31},
		{3, 30},
		{4, 31},
		{5, 30},
		{6, 31},
		{7, 31},
		{8, 30},
		{9, 31},
		{10, 30},
		{11, 31},
	};
	size_t start = 0;
	char *divPtr;
	long year = std::strtol(dtStr.c_str(), &divPtr, 10);
	//TODO - проверить на переполнение
	if (year < 1900)
		throw InvalidFileFormatException();
	date.tm_year = year - 1900;

	long month = std::strtol(divPtr, &divPtr, 10);
	//TODO - проверить на переполнение
	if (month < 1 || month > 12)
		throw InvalidFileFormatException();
	date.tm_mon = month - 1;

	long day = std::strtol(divPtr, &divPtr, 10);
	//TODO - проверить на переполнение
	int maxVal = daysInMonths[month];
	if (month == 1 && isLeapYear(year))
		maxVal = 29;
	if (day < 1 || month > maxVal)
		throw InvalidFileFormatException();
	date.tm_mday = day;

	return std::mktime(&date);

	//for (uint i = 0; i < 2; i ++)
	//{
	//	size_t end = dtStr.find('-', end);
	//	if (end == string::npos)
	//		throw InvalidFileFormatException();
	//	string dateConstr(dtStr, start, end);
	//	if (i == 0)
	//	{
	//		int year = std::strtol(dateConstr.c_str(), dateConstr.c_str() + end, 10);
	//		if (year < 0)
	//			throw InvalidFileFormatException();
	//	}
	//}
}

bool BitcoinExchange::isLeapYear(long year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

const char *BitcoinExchange::InvalidFileFormatException::what() const throw()
{
	return "File's data has invalid format!";
}

