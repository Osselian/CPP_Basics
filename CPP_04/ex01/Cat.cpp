#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat() : Animal(), brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat constructor called!" << std::endl;
}

Cat::Cat(const Cat &origin) : Animal(origin) 
{
	brain = new Brain();
	*brain = *(origin.brain);
	std::cout << "Cat copy constructor called!" << std::endl;
}

const Cat &Cat::operator=(const Cat &other)
{
	*brain = *(other.brain);
	Animal::operator=(other);
	std::cout << "Cat assignment operator called!" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete brain;
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