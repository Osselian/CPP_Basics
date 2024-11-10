#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <cstdlib>

void PhoneBook::AddContact()
{
	if (_addInd == 8)
		_addInd = 0;

	_contacts[_addInd].SetName(GetValue("Enter name: "));
	_contacts[_addInd].SetLastName(GetValue("Enter last name: "));
	_contacts[_addInd].SetNickName(GetValue("Enter nickname: "));
	_contacts[_addInd].SetPhoneNumber(GetValue("Enter phone number: "));
	_contacts[_addInd].SetSecret(GetValue("Enter secret: "));

	_addInd++;
}

void PhoneBook::Search(void)
{
	int i;
	std::string buff;

	PrintContacts();
	std::cout << "Enter contact index: ";
	std::getline(std::cin , buff);
	if (!CheckAlNum(buff.c_str()))
	{
		std::cout << "Invalid index!" << std::endl;
		return ;
	}
	i = std::atoi(buff.c_str());
	if (i > 7)
		std::cout << "Index out of range!" << std::endl;
	else if (_contacts[i].GetName().length() == 0)
		std::cout << "No contact by this index!" << std::endl;
	else
	{
		std::cout << "Name: " << _contacts[i].GetName() << std::endl;
		std::cout << "Last Name: " << _contacts[i].GetLastName() << std::endl;
		std::cout << "Nickname: " << _contacts[i].GetNickName() << std::endl;
		std::cout << "Phone Number: " << _contacts[i].GetPhoneNumber() << std::endl;
		std::cout << "Darkets Secret: " << _contacts[i].GetSecret() << std::endl;
	}
}

std::string PhoneBook::GetValue(const char *mes)
{
	std::string	buff;


	while (true)
	{
		std::cout << mes;
		std::getline(std::cin , buff);
		buff.erase(0, buff.find_first_not_of(" "));
		if (buff.length() > 0)
			return buff;
		std::cout << "Empty values are forbidden!" << std::endl;
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
