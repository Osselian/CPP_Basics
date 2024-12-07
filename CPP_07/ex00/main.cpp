#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(time(0));

	std::cout << "Fist: ";
	Base *first = Base::generate();
	Base::identify(first);
	
	std::cout << "Second: ";
	Base *second = Base::generate();
	Base::identify(second);

	std::cout << "Third: ";
	Base *third = Base::generate();
	Base::identify(third);


	std::cout << "Fourth: ";
	Base &fourth = *Base::generate();
	Base::identify(fourth);
	
	std::cout << "Fifth: ";
	Base &fifth = *Base::generate();
	Base::identify(fifth);

	std::cout << "Six: ";
	Base &six = *Base::generate();
	Base::identify(six);

	delete first;
	delete second;
	delete third;
	delete &fourth;
	delete &fifth;
	delete &six;
}