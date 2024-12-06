#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;

	data.c = 'a';
	data.i = 22;
	data.f = 45.2;
	data.d = 786.082;

	uintptr_t ptr = Serializer::serialize(&data);

	Data *sData = Serializer::deserialize(ptr);

	std::cout << sData->c << std::endl;
	std::cout << sData->i << std::endl;
	std::cout << sData->f << std::endl;
	std::cout << sData->d << std::endl;
}