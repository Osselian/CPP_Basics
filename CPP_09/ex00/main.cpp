#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cerr << "Wrong args number!\n";
		return 1;
	}
	try
	{
		BitcoinExchange btcEx;
		btcEx.setMap("data.csv");
		btcEx.printCurrency(argv[1]);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
