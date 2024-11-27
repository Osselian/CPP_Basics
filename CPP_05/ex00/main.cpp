#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	Bureaucrat b1;
	Bureaucrat b2("Bob", 1);

	try
	{
		Bureaucrat b3("Rob", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b4("Kob", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		b1.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		b2.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}