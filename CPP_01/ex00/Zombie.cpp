#include "Zombie.hpp"
#include <iostream>

Zombie::~Zombie()
{
	std::cout << _name << " was destroyed!" << std::endl;
}

void Zombie::SetName(std::string name)
{
	_name = name;
}

void Zombie::Say()
{
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}