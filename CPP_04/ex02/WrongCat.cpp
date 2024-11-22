#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat constructor called!" << std::endl;
}

 WrongCat::WrongCat(const WrongCat &origin) : WrongAnimal(origin)
{
	std::cout << "WrongCat copy constructor called!" << std::endl;
}

const WrongCat &WrongCat::operator=(const WrongCat &other)
{
	WrongAnimal::operator=(other);
	return *this;
}

 WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called!" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << type + ": Meow!" << std::endl;
}

const std::string &WrongCat::getType() const
{
	return type;
}