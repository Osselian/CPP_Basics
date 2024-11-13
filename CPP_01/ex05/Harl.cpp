#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
	_levels[0] = "debug";	
	_levels[1] = "info";	
	_levels[2] = "warning";	
	_levels[3] = "error";	

	_funcs[0] = &Harl::debug;
	_funcs[1] = &Harl::info;
	_funcs[2] = &Harl::warning;
	_funcs[3] = &Harl::error;
}

void Harl::debug(void)
{
	std::cout << "debug" << std::endl;
}

void Harl::info(void)
{
	std::cout << "info" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "warning" << std::endl;
}

void Harl::error(void)
{
	std::cout << "error" << std::endl;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (_levels[i] == level)
		{
			(this->*_funcs[i])();
			break;
		}
	}
}