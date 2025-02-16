#include "PmergeMe.hpp"
#include "PmergeMeList.hpp"
#include <iostream>

int main(int argc, char **argv) 
{
	(void)argc;
	int i = 1;
	while (argv[i] != NULL)
	{
		std::cout << argv[i] << " ";
		i++;
	}
	std::cout << std::endl;
	PmergeMe FJSort;
	std::deque<int> result = FJSort.sort(argv + 1);
	std::cout << "DEQUE RESULT:" << std::endl;
	for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << " ";
	} 
	std::cout << std::endl;

	PmergeMeList listSort;
	std::list<int> listResult = listSort.sort(argv + 1);
	std::cout << "LIST RESULT:" << std::endl;
	listi::iterator it_b = listResult.begin();
	listi::iterator it_e = listResult.end();
	while(it_b != it_e)
	{
		std::cout << *it_b << " ";
		it_b++;
	} 
	std::cout << std::endl;
	return 0;
}
