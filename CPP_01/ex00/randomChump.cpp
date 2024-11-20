#include "Zombie.hpp"

void randomChump(std::string &name)
{
	Zombie random;
	random.setName(name);
	random.announce();
}