#ifndef ZOMBIE
# define ZOMBIE

#include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(std::string &name);
		~Zombie();
		void setName(std::string &name);
		void announce(void);
};

Zombie *newZombie(std::string &name);

void randomChump(std::string &name);

#endif