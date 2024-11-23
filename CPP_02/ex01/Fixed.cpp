#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_val = 0;
}

Fixed::Fixed(int const val) : _val(val << _frac)
{
	std::cout << "Constructor with int argument called" << std::endl;
}

Fixed::Fixed(float const val)
{
	_val = roundf(val * (1 << _frac));
	std::cout << "Constructor with float argument called" << std::endl;
}

Fixed::Fixed(const Fixed &origin)
{
	std::cout << "Copy constructor called" << std::endl;
	_val = origin.getRawBits();
}

const Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_val = other.getRawBits();

	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits method called" << std::endl;
	return _val;
}

void Fixed::setRawBits(int const raw)
{
	_val = raw;
}

float Fixed::toFloat(void) const
{
	float res = (float)(_val) / (1 << _frac);
	
	return res;
}

int Fixed::toInt(void) const
{
	return _val / (1 << _frac);
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
}