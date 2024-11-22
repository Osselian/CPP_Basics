#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_attackDmg = 20;
	_energy = 50;
	_hitPoints = 100;
	std::cout << "ScavTrap " << _name << " constructor called." << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &origin) : ClapTrap(origin)
{
	std::cout << "ScavTrap " << _name << " copy constructor called." << std::endl;
}

const ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	doAttack("ScavTrap", target);
}