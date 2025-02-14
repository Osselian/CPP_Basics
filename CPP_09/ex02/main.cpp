#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) 
{
	(void)argc;
	PmergeMe FJSort;
	std::deque<int> result = FJSort.sort(argv + 1);
	std::cout << "RESULT:" << std::endl;
	for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << " ";
	} 
	std::cout << std::endl;
	return 0;
}
