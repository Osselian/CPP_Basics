#include "Bureaucrat.hpp"
#include <exception>
#include <i386/endian.h>
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
		std::cout << "b1 name: " << b1.getName() << std::endl;
		std::cout << "b1 grade: " << b1.getGrade() << std::endl;
		b1.incrementGrade();
		std::cout << "b1 grade: " << b1.getGrade() << std::endl;
		b1.decrementGrade();
		std::cout << "b1 grade: " << b1.getGrade() << std::endl;
		b1.decrementGrade();
		std::cout << "b1 grade: " << b1.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "b2 name: " << b2.getName() << std::endl;
		std::cout << "b2 grade: " << b2.getGrade() << std::endl;
		b2.decrementGrade();
		std::cout << "b2 grade: " << b2.getGrade() << std::endl;
		b2.incrementGrade();
		std::cout << "b2 grade: " << b2.getGrade() << std::endl;
		b2.incrementGrade();
		std::cout << "b2 grade: " << b2.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}