#ifndef WRONG_CAT
# define WRONG_CAT

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public: 
		WrongCat();
		WrongCat(const WrongCat &origin);
		const WrongCat &operator=(const WrongCat &other);
		~WrongCat();
		void makeSound(void) const;
		const std::string &getType() const;
};

#endif