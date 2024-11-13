#include <climits>
#include <iostream>


int main(void)
{
	std::string hello = "HI THIS IS BRAIN";

	std::string *stringPTR = &hello;
	std::string &stringREF = hello;

	std::cout << "Variable address: " << &hello << std::endl;
	std::cout << "Variable address in stringPTR: " << stringPTR << std::endl;
	std::cout << "Variable address in stringREF: " << &stringREF << std::endl;

	std::cout << "Value in variable: " << hello << std::endl;
	std::cout << "Value in variable by pointer: " << *stringPTR << std::endl;
	std::cout << "Value in variable by reference: " << stringREF << std::endl;

	return (0);
}