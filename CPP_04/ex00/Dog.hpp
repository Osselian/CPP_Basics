#ifndef DOG
# define DOG

#include "Animal.hpp"

class Dog : public Animal
{
	public: 
		Dog();
		Dog(const Dog &origin);
		const Dog &operator=(const Dog &other);
		virtual ~Dog();
		void makeSound(void) const;
		const std::string &getType() const;
};

#endif