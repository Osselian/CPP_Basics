#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
{
	_attackDmg = 30;
	_energy = 100;
	_hitPoints = 100;
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_attackDmg = 30;
	_energy = 100;
	_hitPoints = 100;
	std::cout << "FragTrap " << _name << " constructor called." << std::endl;
}


FragTrap::FragTrap(const FragTrap &origin) : ClapTrap(origin)
{
	std::cout << "FragTrap " << _name << " copy constructor called." << std::endl;
}

const FragTrap &FragTrap::operator=(const FragTrap &other)
{
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << ": HIGH FIVE GUYS!!!" << std::endl;
}