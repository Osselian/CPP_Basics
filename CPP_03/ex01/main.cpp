#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("A");
	ScavTrap b("B");
	ScavTrap c(a);

	a.attack("B");
	a.takeDamage(5);
	a.takeDamage(0);
	a.takeDamage(-5);
	a.beRepaired(4);

	a = b;
	a.takeDamage(9);
	a.beRepaired(4);
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.beRepaired(4);
	a.beRepaired(4);
	a.beRepaired(4);
	a.guardGate();
}