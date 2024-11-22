#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energy(10), _attackDmg(0)
{
	std::cout << "ClapTrap " << _name << " constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &origin)
{
	_name = origin._name;
	_attackDmg = origin._attackDmg;
	_energy = origin._energy;
	_hitPoints = origin._hitPoints;

	std::cout << "ClapTrap " << _name << " copy constructor called." << std::endl;
}

const ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_attackDmg = other._attackDmg;
		_energy = other._energy;
		_hitPoints = other._hitPoints;
	}

	std::cout << "ClapTrap " << _name << " assignment operator called." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_energy > 0 && _hitPoints > 0)
	{
		_energy--;
		std::cout << "ClapTrap " << _name << " attack " << target << ", causing ";
		std::cout << _attackDmg << " points of damage!" << std::endl;
	}
	else if (_energy == 0)
		std::cout << "ClapTrap " << _name << " can't attack, no energy! " << std::endl;
	else
		std::cout << "ClapTrap " << _name << " can't attack, no hit points! " << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " take " << amount << " damage!" << std::endl;;
		if (_hitPoints <= amount)
		{
			_hitPoints = 0;
			std::cout << "ClapTrap " << _name << " is dead!" << std::endl;;
		}
		else
		 _hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy > 0 && _hitPoints > 0)
	{
		_energy--;	
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repair " << amount << " hit points!" << std::endl;;
	}
	else if (_energy == 0)
		std::cout << "ClapTrap " << _name << " can't repair, no energy! " << std::endl;
	else
		std::cout << "ClapTrap " << _name << " can't repair, no hit points! " << std::endl;
}