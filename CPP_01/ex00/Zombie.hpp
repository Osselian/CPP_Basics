#ifndef ZOMBIE
# define ZOMBIE

#include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		~Zombie();
		void SetName(std::string name);
		void Say();
};

#endif