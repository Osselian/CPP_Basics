#ifndef CONTACT
# define CONTACT

#include <string>

class Contact
{
	private:
		std::string _name;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		void SetName(std::string name);
		void SetLastName(std::string name);
		void SetNickName(std::string name);
		void SetPhoneNumber(std::string number);
		void SetSecret(std::string secret);
		std::string GetName();
		std::string GetLastName();
		std::string GetNickName();
		std::string GetPhoneNumber();
		std::string GetSecret();
};

#endif