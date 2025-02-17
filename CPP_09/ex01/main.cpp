#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) 
{
	if (argc > 2)
		return 1;
	RPN rpn;
	try
	{
		long res = rpn.calculate(argv[1]);
		std::cout << "RES: " << res << std::endl;
	}
	catch(std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
