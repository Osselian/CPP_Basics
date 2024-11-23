#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	_val = 0;
}

Fixed::Fixed(int const val) : _val(val << _frac)
{
	// std::cout << "Constructor with int argument called" << std::endl;
}

Fixed::Fixed(float const val) : _val(static_cast<int>(val * (1 << _frac)))
{
	_val = roundf(val * (1 << _frac));
	// std::cout << "Constructor with float argument called" << std::endl;
}

Fixed::Fixed(const Fixed &origin)
{
	// std::cout << "Copy constructor called" << std::endl;
	_val = origin.getRawBits();
}

const Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_val = other.getRawBits();

	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator<(const Fixed &other) const
{
	return _val < other.getRawBits();
}

bool Fixed::operator>(const Fixed &other) const
{
	return _val > other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return _val <= other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return _val >= other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
	return _val != other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
	return _val == other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed res;
	res.setRawBits(_val + other.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed res;
	res.setRawBits(_val - other.getRawBits());
	return res;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed res(toFloat() * other.toFloat());
	return res;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed res(toFloat() / other.toFloat());
	return res;
}

Fixed Fixed::operator++() 
{
	_val += 1;
	return *this;
}

Fixed Fixed::operator++(int mock)
{
	mock = 1;
	Fixed res(*this);
	_val += mock;
	return res;
}

Fixed Fixed::operator--()
{
	_val -= 1;
	return *this;
}

Fixed Fixed::operator--(int mock)
{
	mock = 1;
	Fixed res(*this);
	_val -= mock;
	return res;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits method called" << std::endl;
	return _val;
}

void Fixed::setRawBits(int const raw)
{
	_val = raw;
}

float Fixed::toFloat(void) const
{
	float res = static_cast<float>(_val) / (1 << _frac);
	
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

Fixed &Fixed:: max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

Fixed &Fixed:: min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed &Fixed:: max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}
const Fixed &Fixed:: min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}