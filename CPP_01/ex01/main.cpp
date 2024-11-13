#include "Zombie.hpp"
#include <climits>
#include <iostream>

int main(void)
{
	int N = 1;

	std::cout << "N is " << N << std::endl;
	Zombie *horde = zombieHorde(N,"Marvin");
	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde ;
	
	N = 5;
	std::cout << "N is " << N << std::endl;
	horde = zombieHorde(N,"Marvin");
	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde ;

	N = -5;
	std::cout << "N is " << N << std::endl;
	horde = zombieHorde(N,"Marvin");
	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde ;

	N = INT_MAX / 4;
	std::cout << "N is " << N << std::endl;
	horde = zombieHorde(N,"Marvin");
	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde ;

	return (0);
}