#include "Span.hpp"
#include <vector>
#include <exception>
#include <iostream>
#include <cstdlib>

void subject_test()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void fill_by_number()
{
	Span span(2);

	try 
	{
		span.addNumber(4);
		span.addNumber(28);
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
		span.addNumber(100);

	}
	catch (std::exception &ex) 
	{
		std::cout << "Can't fill range, not enough space" << std::endl;	
	}


}

void fill_with_iter()
{
	Span span;

	int nums[] =
	{
		10, -2, 13, -34, 55
	};

	std::vector<int> vect (nums, nums + sizeof(nums) / sizeof(int));

	try
	{
		span.fill_range(vect.begin(), vect.end());
		std::cout << "Shortest: " << span.shortestSpan() << std::endl;
		std::cout << "Longest: " << span.longestSpan() << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << "Can't fill range, not enough space" << std::endl;	
	}

	int nums2[] =
	{
		20, -1, 33, -14, 55, 92
	};

	std::vector<int> vect2 (nums2, nums2 + sizeof(nums2) / sizeof(int));
	try
	{
		span.fill_range(vect2.begin(), vect2.end());
		std::cout << "Shortest: " << span.shortestSpan() << std::endl;
		std::cout << "Longest: " << span.longestSpan() << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << "Can't fill range, not enough space" << std::endl;	
	}

}
void span_on_empty_or_single_range()
{
	Span span;

	try 
	{
        std::cout << "Shortest: " << span.shortestSpan() << std::endl;
        std::cout << "Longest: " << span.longestSpan() << std::endl;
    } catch (std::exception &ex) 
	{
		std::cout << "Can't get span on empty range" << std::endl;
	}

	span.addNumber(8);
	try 
	{
        std::cout << "Longest: " << span.longestSpan() << std::endl;
        std::cout << "Shortest: " << span.shortestSpan() << std::endl;
    } catch (std::exception &ex) 
	{
		std::cout << "Can't get span on single elemnt range" << std::endl;
	}

}

void load_test(int amount)
{
	Span span(amount);
	std::vector<int> vect(amount);
	int min = 0;

	std::srand(time(0));
	for (int i = 0; i < 10000; i++)
	{
    	int num = min + rand() % (amount - min + 1);
		vect[i] = num;
	}

	try
	{
		span.fill_range(vect.begin(), vect.end());
		std::cout << "Shortest: " << span.shortestSpan() << std::endl;
		std::cout << "Longest: " << span.longestSpan() << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << "ERROR!" << std::endl;	
	}

}

int main() 
{

	std::cout << "Subject test:" << std::endl;
	std::cout << std::endl;

	std::cout << "TEST - Fill by number:" << std::endl;
	fill_by_number();
	std::cout << std::endl;

	std::cout << "TEST - Fill with iterators:" << std::endl;
	fill_with_iter();
	std::cout << std::endl;

	std::cout << "TEST - Span on empty and single element range:" << std::endl;
	span_on_empty_or_single_range();
	std::cout << std::endl;

	std::cout << "TEST - load test 10000:" << std::endl;
	load_test(10000);
	std::cout << "TEST - load test 100000:" << std::endl;
	load_test(100000);
	std::cout << "TEST - load test 1000000:" << std::endl;
	load_test(1000000);
	std::cout << std::endl;

}
