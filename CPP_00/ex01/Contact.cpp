#include "Contact.hpp"

void Contact::SetName(std::string name) {_name = name;}

void Contact::SetLastName(std::string name) {_lastName = name;}

void Contact::SetNickName(std::string name) {_nickName = name;}

void Contact::SetPhoneNumber(std::string number) {_phoneNumber = number;}

void Contact::SetSecret(std::string secret) {_darkestSecret = secret;}

std::string Contact::GetName() {return _name;}

std::string Contact::GetLastName() {return _lastName;}

std::string Contact::GetNickName() {return _nickName;}

std::string Contact::GetPhoneNumber() {return _phoneNumber;}

std::string Contact::GetSecret() {return _darkestSecret;}