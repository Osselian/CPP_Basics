#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << _name << " was destroyed!" << std::endl;
}

void Zombie::setName(std::string &name)
{
	_name = name;
}

void Zombie::announce()
{
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}