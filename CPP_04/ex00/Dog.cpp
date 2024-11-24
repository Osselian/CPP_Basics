#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog constructor called!" << std::endl;
}

Dog::Dog(const Dog &origin) : Animal(origin)
{
	std::cout << "Dog copy constructor called!" << std::endl;
}

const Dog &Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	std::cout << "Dog assignment operator called!" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << ": Bark!" << std::endl;
}

const std::string &Dog::getType() const
{
	return type;
}