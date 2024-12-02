#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	//навалить тестов!

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

	Bureaucrat tom("Tom", 50);
	PresidentialPardonForm pardon;
	RobotomyRequestForm robotomy("Target");
	ShrubberyCreationForm &shrub = *new ShrubberyCreationForm("TRGT");

	Bureaucrat &linda = *new Bureaucrat("Linda", 150);
	try
	{
    	pardon.beSigned(linda);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
    	robotomy.beSigned(linda);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
    	shrub.beSigned(linda);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	Bureaucrat &eric = *new Bureaucrat("Eric", 50);
	try
	{
		eric.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		eric.signForm(robotomy);
		eric.executeForm(robotomy);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		eric.signForm(shrub);
		eric.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete &linda;
	delete &shrub;
}