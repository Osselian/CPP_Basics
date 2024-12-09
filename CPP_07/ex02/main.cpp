#include "Array.hpp"
#include <exception>
#include <iostream>

#define MAX_VAL 750

void myTest()
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

}

int main()
{
	//myTest();
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
		
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//


	return 0;
}

