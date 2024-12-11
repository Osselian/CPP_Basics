#include "iter.hpp"
#include <cctype>
#include <iostream>

void print_inc(int const &i)
{
	std::cout << "NUM: " << i + 1 << std::endl;
}

void print_upper(std::string const &str)
{
	std::string upper = str;
	for (unsigned long i = 0; i < str.length(); i++) 
	{
		upper[i] = std::toupper(str[i]);
    }
	std::cout <<"STR: " << upper << std::endl;
}

void print_dec(int &i)
{
	std::cout << "NUM: " << i - 1 << std::endl;
}

void print_lower(std::string &str)
{
	std::string lower = str;
	for (unsigned long i = 0; i < str.length(); i++) 
	{
		lower[i] = std::tolower(str[i]);
    }
	std::cout <<"STR: " << lower << std::endl;
}

int main()
{
	int nums[] = {
		1,
		2,
		3,
		4
	};

	std::string strs[] = {
		"Hello",
		"World"
	};

	iter(nums, 4, print_inc);
	iter(strs, 2, print_upper);
	iter(nums, 4, print_dec);
	iter(strs, 2, print_lower);

	int *num = NULL;
	iter(num, 4, print_inc);

	void (*func)(int &) = NULL;
	iter(nums, 4, func);
	return 0;
}