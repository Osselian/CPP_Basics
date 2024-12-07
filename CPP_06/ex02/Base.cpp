#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base::~Base()
{
}

Base *Base::generate()
{
    int min = 0, max = 2;
    int type = min + std::rand() % (max - min + 1);
	std::cout << "TYPE: " << type << std::endl;
	switch (type) 
	{
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		case 2:
			return new C();
			break;
	}
	return NULL;
}

void identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	B *b = dynamic_cast<B *>(p);
	if (b)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C *>(p);
	if (c)
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return ;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
		return ;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
		return ;
	}
	catch (std::exception &e)
	{
	}
}