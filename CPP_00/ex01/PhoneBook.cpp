#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <cstdlib>

void PhoneBook::AddContact()
{
	std::string	buff;

	if (_addInd == 8)
		_addInd = 0;
	if (!TryGetValue("Enter name: ", buff))
		return;
	_contacts[_addInd].SetName(buff);
	
	if (!TryGetValue("Enter last name: ", buff))
		return;
	_contacts[_addInd].SetLastName(buff);

	if (!TryGetValue("Enter nickname: ", buff))
		return;
	_contacts[_addInd].SetNickName(buff);
	
	if (!TryGetValue("Enter phone number: ", buff))
		return;
	_contacts[_addInd].SetPhoneNumber(buff);

	if (!TryGetValue("Enter secret: ", buff))
		return;
	_contacts[_addInd].SetSecret(buff);

	_addInd++;
}

void PhoneBook::Search(void)
{
	int i;
	std::string buff;

	PrintContacts();
	std::cout << "Enter contact index: ";
	std::getline(std::cin , buff);
	if (std::cin.eof())
		return;
	if (!CheckAlNum(buff.c_str()))
	{
		std::cout << "Invalid index!" << std::endl;
		return ;
	}
	i = std::atoi(buff.c_str());
	if (i > 7 || i < 0)
		std::cout << "Index out of range!" << std::endl;
	else if (_contacts[i].GetName().length() == 0)
		std::cout << "No contact by this index!" << std::endl;
	else
	{
		std::cout << std::endl << "Name: " << _contacts[i].GetName() << std::endl;
		std::cout << "Last Name: " << _contacts[i].GetLastName() << std::endl;
		std::cout << "Nickname: " << _contacts[i].GetNickName() << std::endl;
		std::cout << "Phone Number: " << _contacts[i].GetPhoneNumber() << std::endl;
		std::cout << "Darkets Secret: " << _contacts[i].GetSecret() << std::endl << std::endl;
	}
}

bool PhoneBook::TryGetValue(const char *mes, std::string &buff)
{
	while (true)
	{
		std::cout << mes;
		std::getline(std::cin , buff);
		if (std::cin.eof())
			return false;
		else
		{
			buff.erase(0, buff.find_first_not_of(" "));
			if (buff.length() > 0)
				return true;
			std::cout << "Empty values are forbidden!" << std::endl;
		}
	}
}


void PhoneBook::PrintContacts(void)
{
	char name[11];

	name[9] = '.';
	name[10] = 0;
	std::cout << std::endl;
	std::cout << std::setw(10) << "#";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname"  << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i;
		std::strncpy(name, _contacts[i].GetName().c_str(), 9);
		std::cout << "|" << std::setw(10) << name;
		std::strncpy(name, _contacts[i].GetLastName().c_str(), 9);
		std::cout << "|" << std::setw(10) << name;
		std::strncpy(name, _contacts[i].GetNickName().c_str(), 9);
		std::cout << "|" << std::setw(10) << name << std::endl;
	}
	std::cout << std::endl;
}

bool PhoneBook::CheckAlNum(const char *str)
{
	while (*str)
	{
		if (!std::isdigit(*str))
			return false;
		str++;
	}
	return (true);
}
