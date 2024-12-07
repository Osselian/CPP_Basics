#include "TypeNotFoundException.hpp"

TypeNotFoundException::TypeNotFoundException()throw(){}

TypeNotFoundException::TypeNotFoundException(const TypeNotFoundException &)throw(){}

const TypeNotFoundException &TypeNotFoundException::operator=(const TypeNotFoundException &)throw()
{
	return *this;
}

TypeNotFoundException::	~TypeNotFoundException()throw(){}

const char *TypeNotFoundException::TypeNotFoundException::what() const throw()
{
	return "Type not found!";
}