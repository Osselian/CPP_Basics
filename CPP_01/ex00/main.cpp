#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *newZombie;

	newZombie = new Zombie();
	newZombie->setName(name);

	return (newZombie);
}

void randomChump(std::string name)
{
	Zombie random;
	random.setName(name);
	random.announce();
}

int main(void)
{
	Zombie *marv = newZombie("Marvin");
	marv->announce();
	delete marv;
	randomChump("Victor");

	return (0);
}