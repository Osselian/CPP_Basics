#include "Zombie.hpp"
#include <climits>
#include <iostream>

void announceAll(int N, Zombie *horde)
{
	if (horde)
	{
		for (int i = 0; i < N; i++)
			horde[i].announce();
    }
}

int main(void)
{
	int N = 1;

	std::cout << "N is " << N << std::endl;
	Zombie *horde = zombieHorde(N,"Marvin");
	announceAll(N, horde);

	delete[] horde ;
	
	N = 5;
	std::cout << "N is " << N << std::endl;
	horde = zombieHorde(N,"Marvin");
	announceAll(N, horde);

	delete[] horde ;

	N = -5;
	std::cout << "N is " << N << std::endl;
	horde = zombieHorde(N,"Marvin");
	announceAll(N, horde);

	delete[] horde ;

	N = INT_MAX / 8;
	std::cout << "N is " << N << std::endl;
	horde = zombieHorde(N,"Marvin");
	announceAll(N, horde);

	delete[] horde ;

	N = INT_MIN;
	std::cout << "N is " << N << std::endl;
	horde = zombieHorde(N,"Marvin");
	announceAll(N, horde);

	delete[] horde ;

	std::cout << "Bye!" << std::endl;
	return (0);
}