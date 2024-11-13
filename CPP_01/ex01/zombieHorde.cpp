#include "Zombie.hpp"
#include <climits>
#include <iostream>

bool handleSignificantInput(int N)
{
	std::string input;

	std::cout << "WARNING: you are going to create " << N
	          << " size horde! Memory usage may be critical! Do "
	             "you want to proceed? yes/no"
	          << std::endl;
	while (1) 
	{
		std::cin >> input;
		if (std::cin.eof() || input.compare("no") == 0)
			return false;
		if (input.compare("yes") == 0)
			break;
		std::cout << "Please, print \"yes\" or \"no\"" << std::endl;
	}
	return true;
}

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *newHorde;

	if (N <= 0)
	{
		std::cout << "A valid positive number required to create a horde!" << std::endl;
		return NULL;
	}
	if (N >= INT_MAX / 8 && !handleSignificantInput(N))
		return NULL;

	newHorde = new Zombie[N];
    for (int i = 0; i < N; i++)
      newHorde[i].setName(name);

    return newHorde;
}