#ifndef DOG
# define DOG

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public: 
		Dog();
		Dog(const Dog &origin);
		const Dog &operator=(const Dog &other);
		virtual ~Dog();
		void makeSound(void) const;
		const std::string &getType() const;
};

#endif