#ifndef PHONEBOOK
# define PHONEBOOK

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int _addInd;
		void PrintContacts(void);
		bool CheckAlNum(const char *str);
		bool TryGetValue(const char *mes, std::string &buff);

	public:
		PhoneBook() {_addInd = 0;}
		void AddContact();
		void Search();
};

#endif