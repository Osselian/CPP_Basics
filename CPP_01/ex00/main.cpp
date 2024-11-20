#include "Zombie.hpp"
#include <string>

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