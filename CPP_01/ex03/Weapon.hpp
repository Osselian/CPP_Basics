#ifndef WEAPON
# define WEAPON

#include <string>
class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		const std::string &getType();
		void setType(std::string type);
};
#endif