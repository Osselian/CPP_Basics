#ifndef SCAV_TRAP
# define SCAV_TRAP
# include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &origin);
		const ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();
		void attack(const std::string &target);
		void guardGate() const;
};

#endif