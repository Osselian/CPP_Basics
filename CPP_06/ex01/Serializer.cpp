#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &)
{
}

const Serializer &Serializer::operator=(const Serializer &)
{
	return *this;
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t res = reinterpret_cast<uintptr_t>(ptr);
	return res;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	void *r = reinterpret_cast<void *>(raw);
	Data *res = static_cast<Data *>(r);
	return res;
}