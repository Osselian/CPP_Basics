#ifndef MUTANT_STACK
# define MUTANT_STACK

#include <stack>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack
{
	private:
		Container _container;
	public:
		MutantStack();
		MutantStack(Container &container); 
		operator std::stack<T, Container>() const ;
		MutantStack(const MutantStack &origin);
		const MutantStack &operator=(const MutantStack &other);
		~MutantStack();

		bool empty() const;
		size_t size() const;
		T &top();
		const T &top() const;
		void push(const T &value);
		void pop();

		class iterator;

		typename MutantStack<T, Container>::iterator begin();
		typename MutantStack<T, Container>::iterator end();


};

template <typename T, typename Container>
class MutantStack<T, Container>:: iterator : public std::iterator<std::input_iterator_tag, T>
{
private:
	T *_ptr;

public:
	iterator(T *x) : _ptr(x) {}
	iterator(const iterator &mit) : _ptr(mit._ptr) {}
	iterator &operator++()
	{
		++_ptr;
		return *this;
	}
	iterator operator++(int)
	{
		iterator tmp(*this);
		operator++();
		return tmp;
	}
	iterator &operator--()
	{
		--_ptr;
		return *this;
	}
	iterator operator--(int)
	{
		iterator tmp(*this);
		operator--();
		return tmp;
	}
	bool operator==(const iterator &other) const
	{
		return _ptr == other._ptr;
	}
	bool operator!=(const iterator &other) const
	{
		return _ptr != other._ptr;
	}
	T &operator*() { return *_ptr; }
};
#endif