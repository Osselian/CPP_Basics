#include "Zombie.hpp"
#include <string>

Zombie *newZombie(std::string name)
{
	return (new Zombie(name));
}

void randomChump(std::string name)
{
	Zombie random;
	random.setName(name);
	random.announce();
}

int main(void)
{
	std::string name = "Marvin";
	Zombie *marv = newZombie(name);
	marv->announce();
	name = "Victor";
	randomChump(name);

	marv->announce();
	delete marv;
	return (0);
}