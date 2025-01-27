#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>:: MutantStack()
{
	_container = Container();
	std::cout << "Default constructor" << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>:: MutantStack(Container &container)
{
	_container = container;
}

template <typename T, typename Container>
MutantStack<T, Container>:: operator std::stack<T, Container>() const
{
	return std::stack<T, Container>(_container);
}

template <typename T, typename Container>
MutantStack<T, Container>:: MutantStack(const MutantStack &origin)
{
	_container = Container(origin._container);
}

template <typename T, typename Container>
const MutantStack<T, Container> &MutantStack<T, Container>::operator=(
	const MutantStack &other)
{
	if (this != &other)
	{
		_container = Container(other._container);
	}
	return *this;
}

template<typename T, typename Container>
MutantStack<T, Container>:: ~MutantStack()
{
}

template<typename T, typename Container>
bool MutantStack<T, Container>:: empty() const
{
	return _container.size() == 0;
}

template<typename T, typename Container>
size_t MutantStack<T, Container>:: size() const
{
	return _container.size();
}

template<typename T, typename Container>
T &MutantStack<T, Container>:: top()
{
	return _container.back();
}

template<typename T, typename Container>
const T &MutantStack<T, Container>:: top() const
{
	return _container.back();
}

template<typename T, typename Container>
void MutantStack<T, Container>:: push(const T &value)
{
	_container.push_back(value);
}

template<typename T, typename Container>
void MutantStack<T, Container>:: pop()
{
	_container.pop_back();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return	iterator(&_container[0]); 
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return	iterator(&_container[_container.size()]); 
}