#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
#include <type_traits>
#include "Intern.hpp"

int main(void)
{
	//навалить тестов!

	Bureaucrat tom("Tom", 50);
	Intern bobby;

	AForm &pardon = *bobby.makeForm("presidential", "Louis");
	std::cout << pardon << std::endl;

	AForm &robotomy = *bobby.makeForm("robotomy", "Robo");
	std::cout << robotomy << std::endl;

	AForm &shrub = *bobby.makeForm("shrubberry", "Shrubs");
	std::cout << shrub << std::endl;


	tom.signForm(pardon);
	tom.signForm(robotomy);
	tom.signForm(shrub);
	tom.executeForm(pardon);
	tom.executeForm(robotomy);
	tom.executeForm(shrub);

	delete &pardon;
	delete &robotomy;
	delete &shrub;

	try 
	{
		AForm *pardony = bobby.makeForm("presidential form", "Louis");
		std::cout << *pardony << std::endl;
		AForm *robotnik = bobby.makeForm("robotomy request", "Robo");
		std::cout << *robotnik << std::endl;
		AForm *shrubba = bobby.makeForm("shrubbery burst", "Shrubs");
		std::cout << *shrubba << std::endl;

		tom.signForm(*pardony);
		tom.signForm(*robotnik);
		tom.signForm(*shrubba);
		tom.executeForm(*pardony);
		tom.executeForm(*robotnik);
		tom.executeForm(*shrubba);
	
		delete pardony;
		delete robotnik;
		delete shrubba;
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}

	try 
	{
		AForm *prdn = bobby.makeForm("presidential form", "Louis");
		std::cout << *prdn << std::endl;
		AForm *rb = bobby.makeForm("robotomy request", "Robo");
		std::cout << *rb << std::endl;
		AForm *shrbb = bobby.makeForm("shrubberry burst", "Shrubs");
		std::cout << *shrbb << std::endl;
		tom.signForm(*prdn);
		tom.signForm(*rb);
		tom.signForm(*shrbb);
		tom.executeForm(*prdn);
		tom.executeForm(*rb);
		tom.executeForm(*shrbb);
	
		delete prdn;
		delete rb;
		delete shrbb;
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}

	{
		Intern bob(bobby);
	}

}