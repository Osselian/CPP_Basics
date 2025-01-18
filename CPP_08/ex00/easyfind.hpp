#ifndef EASYFIND
#define EASYFIND

#include <algorithm>
#include <exception>

template<class T>
typename T::iterator easyfind(T &range, int value)
{
	if (range.size() == 0)
		throw std::exception();
	typename T::iterator it = std::find(range.begin(), range.end(), value);
	if (it != range.end())
		return it;
	throw std::exception();
}

#endif