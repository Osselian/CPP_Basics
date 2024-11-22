#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("A");
	ClapTrap b("B");
	ClapTrap c(a);

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
}