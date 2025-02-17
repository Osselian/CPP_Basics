#include "PmergeMe.hpp"
#include "PmergeMeList.hpp"
#include <iostream>

int main(int argc, char **argv) 
{
	(void)argc;
	double deqElapsed;
	double listElapsed;
	std::deque<int> result;
	std::list<int> listResult ;
	try
	{
		PmergeMe FJSort;
		clock_t start = clock();
		result = FJSort.sort(argv + 1);
		clock_t end = clock();
		deqElapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

		PmergeMeList listSort;
		clock_t lstart = clock();
		listResult = listSort.sort(argv + 1);
		clock_t lend = clock();
		listElapsed = static_cast<double>(lend - lstart) / CLOCKS_PER_SEC * 1000.0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "ERROR" << '\n';
		return 1;
	}

	int i = 1;
	std::cout << "Before: ";
	while (argv[i] != NULL)
	{
		std::cout << argv[i] << " ";
		i++;
	}
	std::cout << std::endl;

	std::cout << "After:" << std::endl;
	listi::iterator it_b = listResult.begin();
	for (size_t i = 0; i < result.size(); i++)
	{
		if (result[i] == *it_b)
			std::cout << result[i] << " ";
		else
			throw std::exception();
		it_b++;
	} 
	std::cout << std::endl;

	std::cout << "Time to process a range of " << result.size();
	std::cout << " elements with std::deque : " << deqElapsed << " miliseconds";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << result.size();
	std::cout << " elements with std::list : " << listElapsed << " miliseconds"; 
	std::cout << std::endl;

	return 0;
}
