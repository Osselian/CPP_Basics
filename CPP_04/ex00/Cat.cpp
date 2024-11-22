#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat constructor called!" << std::endl;
}

Cat::Cat(const Cat &origin) : Animal(origin)
{
	std::cout << "Cat copy constructor called!" << std::endl;
}

const Cat &Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << ": Meow!" << std::endl;
}

const std::string &Cat::getType() const
{
	return type;
}