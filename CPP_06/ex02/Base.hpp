#ifndef BASE
# define BASE

class Base
{
	public:
		virtual ~Base();
		static Base *generate(void);
};

void identify(Base *p);
void identify(Base &p);
#endif