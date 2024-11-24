#include "ScavTrap.hpp"
#include <climits>

int main()
{
	ScavTrap a("A");
	ScavTrap b("B");
	ScavTrap c(a);

	a.showStats();
	a.attack("B");
	a.showStats();
	for (int i = 0; i < 3; i++){
		a.takeDamage(25);
		a.showStats();
	}
	a.beRepaired(4);
	a.showStats();

	a = b;
	a.takeDamage(9);
	a.showStats();
	a.beRepaired(4);
	a.showStats();
	//do cycle
	for (int i = 0; i < 55; i++){
		a.attack("B");
		a.showStats();
	}
	for (int i = 0; i < 3; i++){
		a.beRepaired(4);
		a.showStats();
	}

	c.beRepaired(INT_MIN);
	c.showStats();
	c.beRepaired(UINT_MAX);
	c.showStats();
	c.beRepaired(UINT_MAX);
	c.showStats();
	c.beRepaired(1);
	c.showStats();
	c.takeDamage(UINT_MAX);
	c.showStats();

	ScavTrap &d = *new ScavTrap();

	d.showStats();
	d.attack("B");
	d.showStats();
	for (int i = 0; i < 3; i++){
		d.takeDamage(5);
		d.showStats();
	}
	d.beRepaired(4);
	d.showStats();

	d.takeDamage(9);
	d.showStats();
	d.beRepaired(4);
	d.showStats();
	//do cycle
	for (int i = 0; i < 15; i++){
		d.attack("B");
		d.showStats();
	}
	for (int i = 0; i < 3; i++){
		d.beRepaired(4);
		d.showStats();
	}
	delete &d;
}