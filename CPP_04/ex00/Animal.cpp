#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Unspecified")
{
	std::cout << "Animal constructor called!" << std::endl;
}

Animal::Animal(const Animal &origin)
{
	type = origin.type;
	std::cout << "Animal copy constructor called!" << std::endl;
}

const Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Animal assignment operator called!" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << ": unspecified sounds" << std::endl;
}
 
const std::string &Animal::getType() const
{
	return type;
}