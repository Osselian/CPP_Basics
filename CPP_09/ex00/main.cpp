#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) 
{
	(void)argc;
	BitcoinExchange btcEx;
	// try
	// {
	// 	btcEx.setMap("tests/tst1_data.csv");
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	try
	{
		btcEx.setMap("data.csv");
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
