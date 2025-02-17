#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cerr << "Wrong args number\n";
		return 1;
	}
	RPN rpn;
	try
	{
		long res = rpn.calculate(argv[1]);
		std::cout << res << std::endl;
	}
	catch(std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
