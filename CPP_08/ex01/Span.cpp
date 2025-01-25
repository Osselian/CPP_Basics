#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <exception>
#include <iterator>
#include <iostream>
#include <vector>

Span::Span() : _capacity(10), _current(0)
{
	_container = new std::vector<int>(10);
}

Span::Span(unsigned int N) : _capacity(N), _current(0)
{
	_container = new std::vector<int>(N);
}

Span::Span(const Span &origin) : _capacity(origin._capacity)
{
	_container = new std::vector<int>(*origin._container);	
	_current = origin._current;
}

const Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		delete _container;
		_capacity = other._capacity;
        _container = new std::vector<int>(*other._container);
        _current = other._current;
    }
    return *this;
}

Span::~Span()
{
	delete _container;
}

void Span::addNumber(int numb)
{
	if (_current == _capacity)
		throw std::exception();
	(*_container)[_current] = numb;
	_current++;
}

unsigned int Span::shortestSpan() const
{
	if (_current <= 1)
		throw std::exception();
	std::vector<int> res = getSpan();
	return *std::min_element(res.begin(), res.end());
}

unsigned int Span::longestSpan() const
{
	if (_current <= 1)
		throw std::exception();
	std::vector<int> res = getSpan();
	return *std::max_element(res.begin(), res.end());
}

std::vector<int> Span::getSpan() const
{
	std::vector<int> res(_current - 1);

	std::transform(
		_container->begin(), 
		_container->begin() + _current - 1, 
		_container->begin() + 1, 
		res.begin(), 
		std::minus<int>());

	std::transform(
		res.begin(), 
		res.end(), 
		res.begin(), 
		static_cast<int(*)(int)>(std::abs));

	return res;
}

void Span::fill_range(iter start, iter end)
{
	unsigned int dist = std::distance(start, end);
	if (dist  > _capacity - _current)
		throw std::exception();
	std::copy(start, end, _container->begin() + _current);
	_current += dist;
}