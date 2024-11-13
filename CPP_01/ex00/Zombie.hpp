#ifndef ZOMBIE
# define ZOMBIE

#include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		~Zombie();
		void setName(std::string name);
		void announce(void);
};

#endif