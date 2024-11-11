#include "PhoneBook.hpp"
#include <iostream>

int findCommand(std::string command)
{
	std::string commands[3] = 
	{
		"ADD",
		"SEARCH",
		"EXIT"
	};
	for(int i = 0; i < 3; i++)
	{
		if (commands[i].compare(command) == 0)
			return i;
	}
	return -1;
}

int	main(void)
{
	PhoneBook phoneBook;
	std::string	command;

	while(true)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin , command);
		if (std::cin.eof())
			break;

		switch (findCommand(command)) 
		{
			case 0:
				phoneBook.AddContact();
				break;
			case 1:
				phoneBook.Search();
				break;
			case 2:
				return 0;
			default:
				std::cout << "Invalid command!" << std::endl;
				break;
		}
		if (std::cin.eof())
			break;
	}
	return 0;
}
