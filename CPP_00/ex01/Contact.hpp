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
		void SetName(std::string name) {_name = name;}
		void SetLastName(std::string name) {_lastName = name;}
		void SetNickName(std::string name) {_nickName = name;}
		void SetPhoneNumber(std::string number) {_phoneNumber = number;}
		void SetSecret(std::string secret) {_darkestSecret = secret;}
		std::string GetName() {return _name;}
		std::string GetLastName() {return _lastName;}
		std::string GetNickName() {return _nickName;}
		std::string GetPhoneNumber() {return _phoneNumber;}
		std::string GetSecret() {return _darkestSecret;}
};

#endif