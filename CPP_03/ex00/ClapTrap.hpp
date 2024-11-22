#ifndef CLAP_TRAP
#define CLAP_TRAP

#include <string>
class ClapTrap
{
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energy;
		unsigned int _attackDmg;
	public:
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &origin);
		const ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif