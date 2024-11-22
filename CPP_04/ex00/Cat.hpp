#ifndef CAT
# define CAT

#include "Animal.hpp"

class Cat : public Animal
{
	public: 
		Cat();
		Cat(const Cat &origin);
		const Cat &operator=(const Cat &other);
		virtual ~Cat();
		void virtual makeSound(void) const;
		const std::string &getType() const;
};

#endif