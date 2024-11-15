#include "Fixed.hpp"
#include <iostream>
#include <ostream>

int main(void)
{
	Fixed a(1);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "Bools:" << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl << std::endl;

	std::cout << "b + a = " << (b + a) << std::endl;
	std::cout << "b - a = " << (b - a) << std::endl;
	std::cout << "b * a = " << (b * a) << std::endl;
	std::cout << "b / a = " << (b / a) << std::endl << std::endl;

	std::cout << "Increment/Decrement on a:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl << std::endl;

	std::cout << "b: " << b << std::endl << std::endl;

	std::cout << "b + a = " << (b + a) << std::endl;
	std::cout << "b - a = " << (b - a) << std::endl;
	std::cout << "b * a = " << (b * a) << std::endl;
	std::cout << "b / a = " << (b / a) << std::endl << std::endl;

	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "max of a, b: " << Fixed::max( a, b ) << std::endl;
	std::cout << "min of a, b: " << Fixed::min( a, b ) << std::endl << std::endl;
	Fixed c(  2 );
	std::cout << "a: " << a << ", c: " << c << std::endl;
	std::cout << "max of a, c: " << Fixed::max( a, c ) << std::endl;
	std::cout << "min of a, c: " << Fixed::min( a, c ) << std::endl << std::endl;
	
	return (0);
}