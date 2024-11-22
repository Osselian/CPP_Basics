#ifndef WRONG_ANIMAL
# define WRONG_ANIMAL

#include <string>
class WrongAnimal 
{
	protected:
		std::string type;
	public: 
		WrongAnimal();
		WrongAnimal(const WrongAnimal &origin);
		const WrongAnimal &operator=(const WrongAnimal &other);
		~WrongAnimal();
		void makeSound() const;
		const std::string &getType() const;
};

#endif