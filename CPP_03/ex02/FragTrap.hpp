#ifndef FRAG_TRAP
# define FRAG_TRAP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &origin);
		const FragTrap &operator=(const FragTrap &other);
		~FragTrap();
		void highFivesGuys(void);
};

#endif