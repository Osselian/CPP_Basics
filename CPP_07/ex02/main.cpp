#include "Array.hpp"
#include <exception>
#include <iostream>

int main()
{
	Array<int> znums;

	Array<int> nums(5);

	Array<int> *allocted = new Array<int>(10);

	std::cout << "znums size: " << znums.size() << std::endl;
	std::cout << "nums size: " << nums.size() << std::endl;
	std::cout << "allocted size: " << allocted->size() << std::endl;
	try 
	{
		std::cout << znums[0] << std::endl;	 	
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;	 	
	}

	try 
	{
		znums[0] = 7;
		std::cout << znums[0] << std::endl;	 	
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;	 	
	}

	try 
	{
		std::cout << nums[0] << std::endl;	 	
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;	 	
	}
	try 
	{
		nums[0] = 7;
		std::cout << nums[0] << std::endl;	 	
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;	 	
	}

	try 
	{
		std::cout << (*allocted)[0] << std::endl;	 	
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;	 	
	}
	try 
	{
		(*allocted)[0] = 7;
		std::cout << nums[0] << std::endl;	 	
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;	 	
	}

	try
	{
		znums = *allocted;
		znums[0] = 10;
		std::cout << "znums[0]: " << znums[0] << ", allocted[0]: ";
		std::cout << (*allocted)[0] << std::endl;
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;	 	
	}

	{
		Array<int> nums;
	}

	int *a = new int();
	std::cout << "int is " << *a << std::endl;


	{
		Array<const std::string> strs(5);
		std::string first = strs[0];
		// strs[0] = "a";
	}
	delete allocted;
	delete a;

	return 0;
}
