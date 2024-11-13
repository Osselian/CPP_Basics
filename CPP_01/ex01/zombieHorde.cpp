#include "Zombie.hpp"
#include <climits>
#include <iostream>

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *newHorde;

	if (N <= 0)
	{
		std::cout << "A valid positive number required to create a horde!" << std::endl;
		return NULL;
	}
	if (N > INT_MAX)
	{
		std::cout << "WARNING: you are going to create " << N << " size horde! Memory usage may be critical!" << std::endl;
		return NULL;
	}
	newHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		newHorde[i].setName(name);

	return newHorde;
}