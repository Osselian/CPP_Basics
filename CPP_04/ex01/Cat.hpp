#ifndef CAT
# define CAT

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public: 
		Cat();
		Cat(const Cat &origin);
		const Cat &operator=(const Cat &other);
		virtual ~Cat();
		void virtual makeSound(void) const;
		const std::string &getType() const;
};

#endif