#ifndef BRAIN
# define BRAIN

#include <string>
class Brain
{
	public:
		Brain();
		Brain(const Brain &origin);
		const Brain &operator=(const Brain &other);
		~Brain();
		std::string ideas[100];
};

# endif