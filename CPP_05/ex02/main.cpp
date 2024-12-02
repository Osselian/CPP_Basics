#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	{
		Bureaucrat tom("Tom", 50);
		PresidentialPardonForm pardon;
		RobotomyRequestForm robotomy("Robo");
		ShrubberyCreationForm &shrub = *new ShrubberyCreationForm("Shrubs");

		Bureaucrat &linda = *new Bureaucrat("Linda", 150);
		try
		{
			linda.signForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			linda.signForm(robotomy);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			linda.signForm(shrub);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		delete &linda;
		delete &shrub;
	}

	{
		PresidentialPardonForm pardon;
		RobotomyRequestForm robotomy("Robo");
		ShrubberyCreationForm &shrub = *new ShrubberyCreationForm("Shrubs");

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
		delete &eric;
		delete &shrub;
	}

	{
		PresidentialPardonForm pardon;
		RobotomyRequestForm robotomy("Robo");
		ShrubberyCreationForm &shrub = *new ShrubberyCreationForm("Shrubs");

		Bureaucrat &rick = *new Bureaucrat("Rick", 1);
		try
		{
			rick.executeForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			rick.signForm(robotomy);
			rick.executeForm(robotomy);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			rick.signForm(shrub);
			rick.executeForm(shrub);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		delete &rick;
		delete &shrub;
	}
}