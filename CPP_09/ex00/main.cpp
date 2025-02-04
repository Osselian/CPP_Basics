#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) 
{
	(void)argc;
	(void)argv;
	BitcoinExchange btcEx;
	try
	{
		btcEx.setMap("data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
