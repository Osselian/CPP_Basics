#include "ScalarConverter.hpp"
#include <exception>
#include <iomanip>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments!\n";
		return (1);
	}

	try 
	{
		ScalarConverter::convert(argv[1]);		
		std::cout << "DONE!" << std::endl;
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}
}