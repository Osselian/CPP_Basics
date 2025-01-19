#include "Span.hpp"
#include <vector>
#include <exception>
#include <iostream>
#include <cstdlib>

int main() 
{

	std::cout << "Subject test:" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << "My test1:" << std::endl;

	Span span;

	int nums[] =
	{
		10, -2, 13, -34, 55
	};

	std::vector<int> vect (nums, nums + sizeof(nums) / sizeof(int));

	span.fill_range(vect.begin(), vect.end());

	std::cout << "Shortest: " << span.shortestSpan() << std::endl;
	std::cout << "Longest: " << span.longestSpan() << std::endl;
}
