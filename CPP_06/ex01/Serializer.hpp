#ifndef SERIALIZER
# define SERIALIZER

typedef unsigned long uintptr_t;

struct Data
{
	char c;
	int i;
	float f;
	double d;
};

class Serializer
{
	private:	
		Serializer();
		Serializer(const Serializer &origin);
		const Serializer &operator=(const Serializer &other);
		~Serializer();
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif