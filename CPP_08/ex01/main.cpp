#include "easyfind.hpp"
#include <deque>
#include <iterator>
#include <vector>
#include <exception>
#include <iostream>
#include <cstdlib>
#include <list>

void test_vector(int *nums, int size) 
{
  std::cerr << "TEST VECTOR:" << std::endl;
  std::vector<int> vect(nums, nums + size / sizeof(int));
  try 
  {
    std::vector<int>::iterator first = easyfind(vect, 2);
    std::cout << "First val: " << *first << std::endl;
    std::cout << "Index: " << std::distance(vect.begin(), first) << std::endl;
  } 
  catch (std::exception &ex) 
  {
    std::cerr << "ERROR!" << std::endl;
  }
}

void test_deque(int *nums, int size) 
{
  std::cerr << "TEST DEQUE:" << std::endl;
  std::deque<int> deq(nums, nums + size / sizeof(int));
  try 
  {
    std::deque<int>::iterator first = easyfind(deq, 2);
    std::cout << "First: " << *first << std::endl;
    std::cout << "Index " << std::distance(deq.begin(), first) << std::endl;
  } 
  catch (std::exception &ex) 
  {
    std::cerr << "ERROR!" << std::endl;
  }
}

void test_list(int *nums, int size) 
{
  std::cerr << "TEST LIST:" << std::endl;
  std::list<int> lst(nums, nums + size / sizeof(int));
  try 
  {
    std::list<int>::iterator first = easyfind(lst, 2);
    std::cout << "First: " << *first << std::endl;
    std::cout << "Index " << std::distance(lst.begin(), first) << std::endl;
  } 
  catch (std::exception &ex) 
  {
    std::cerr << "ERROR!" << std::endl;
  }
}

int main() 
{
	int nums[] = {1, 2, 3, 4, 5};

	test_vector(nums, sizeof(nums));
	test_deque(nums, sizeof(nums));
	test_list(nums, sizeof(nums));

	int nums2[] = {1,  3, 4, 5,  3, 2};

	test_vector(nums2, sizeof(nums2));
	test_deque(nums2, sizeof(nums2));
	test_list(nums2, sizeof(nums2));

	int nums3[] = {1, 3, 4, 5,  3};

	test_vector(nums3, sizeof(nums3));
	test_deque(nums3, sizeof(nums3));
	test_list(nums3, sizeof(nums3));
}
