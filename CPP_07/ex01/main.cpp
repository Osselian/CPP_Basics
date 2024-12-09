#include "iter.hpp"
#include <iostream>

void print_num(int i)
{
	std::cout << "NUM: " << i << std::endl;
}

void print_str(std::string str)
{
	std::cout << "STR: " << str << std::endl;
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

	iter(nums, 4, print_num);
	iter(strs, 2, print_str);
	return 0;
}