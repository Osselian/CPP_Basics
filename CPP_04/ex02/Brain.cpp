#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain constructor called!" << std::endl;
}

Brain::Brain(const Brain &origin)
{
	std::cout << "Brain copy constructor started!" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = origin.ideas[i];
	}
	std::cout << "Brain copy constructor called!" << std::endl;
}

const Brain &Brain::operator=(const Brain &other)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain assignement operator called!" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!" << std::endl;
}