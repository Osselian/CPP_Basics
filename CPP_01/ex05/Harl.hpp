#ifndef HARL
# define HARL

#include <string>

class Harl
{
	private:
		std::string _levels[4];
		void (Harl::*_funcs[4])(void);
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Harl(void);
		void complain(std::string level);
};

#endif