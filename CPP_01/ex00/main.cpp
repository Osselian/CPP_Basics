#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *newZombie;

	newZombie = new Zombie();
	newZombie->SetName(name);

	return (newZombie);
}

void randomChump(std::string name)
{
	Zombie random;
	random.SetName(name);
	random.Say();
}

int main(void)
{
	Zombie *marv = newZombie("Marvin");
	marv->Say();
	delete marv;
	randomChump("Victor");

	return (0);
}