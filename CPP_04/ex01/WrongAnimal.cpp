#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("Unspecified")
{
	std::cout << "WrongAnimal constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &origin)
{
	type = origin.type;
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
}

const WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "WrongAnimal assignment operator called!" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called!" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << ": unspecified sounds" << std::endl;
}

const std::string &WrongAnimal::getType() const
{
	return type;
}