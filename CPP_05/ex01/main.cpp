#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	{
		Bureaucrat tom("Tom", 50);
		Form a;
		Form b("B1", 1, 1);
		try
		{
			Form c("C32", 0, 1);
		}
		catch (std::exception &e)
		{
			std::cout << "Can't create form C32: " << e.what() << std::endl;
		}
		try
		{
			Form d("D-92", 23, 153);
		}
		catch (std::exception &e)
		{
			std::cout << "Can't create form D-92: " << e.what() << std::endl;
		}

		std::cout << a;
		std::cout << b;

		tom.signForm(a);
		tom.signForm(b);
		std::cout << std::endl;
	}

	{
		Form c("C23", 76, 23);
		std::cout << c;
		Bureaucrat &linda = *new Bureaucrat("Linda", 150);
		try
		{
			c.beSigned(linda);
		}
		catch (std::exception &e)
		{
			std::cout << "C23, linda: " << e.what() << std::endl;
		}
		delete &linda;
		std::cout << std::endl;
	}

	{
		Form c("C23", 76, 23);
		std::cout << c;
		Bureaucrat &olaf = *new Bureaucrat("Olaf", 23);
			try
			{
				c.beSigned(olaf);
			}
			catch (std::exception &e)
			{
				std::cout << "C23, olaf: " << e.what() << std::endl;
			}
		delete &olaf;
		std::cout << std::endl;
	}
}