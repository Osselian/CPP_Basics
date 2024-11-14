#ifndef HUMAN_B
# define HUMAN_B

#include "Weapon.hpp"
#include <string>

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		HumanB(std::string &name);
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif