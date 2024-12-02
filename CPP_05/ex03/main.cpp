#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
#include "Intern.hpp"

int main(void)
{
	//навалить тестов!

	Bureaucrat tom("Tom", 50);
	Intern bobby;
	AForm *pardon = bobby.makeForm("presidential", "Louis");
	AForm *robotomy = bobby.makeForm("robotomy", "Robo");
	AForm *shrub = bobby.makeForm("shrubberry", "Shrubs");
	tom.signForm(*pardon);
	tom.signForm(*robotomy);
	tom.signForm(*shrub);
	tom.executeForm(*pardon);
	tom.executeForm(*robotomy);
	tom.executeForm(*shrub);

	try 
	{
		AForm *pardony = bobby.makeForm("presidential form", "Louis");
		AForm *robotnik = bobby.makeForm("robotomy request", "Robo");
		AForm *shrubba = bobby.makeForm("shrubbery burst", "Shrubs");
		tom.signForm(*pardony);
		tom.signForm(*robotnik);
		tom.signForm(*shrubba);
		tom.executeForm(*pardony);
		tom.executeForm(*robotnik);
		tom.executeForm(*shrubba);
	
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}
	delete shrub;
}