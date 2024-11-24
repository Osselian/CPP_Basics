#ifndef ANIMAL
# define ANIMAL

#include <string>
class Animal 
{
	protected:
		std::string type;
	public: 
		Animal();
		Animal(const Animal &origin);
		const Animal &operator=(const Animal &other);
		virtual ~Animal();
		virtual void makeSound() const;
		const std::string &getType() const;
};

#endif