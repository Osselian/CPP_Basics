#ifndef TYPE_NOT_FOUND_EXCEPTION
# define TYPE_NOT_FOUND_EXCEPTION

#include <exception> 

class TypeNotFoundException : public std::exception
{
    public:
		TypeNotFoundException() throw();
		TypeNotFoundException(const TypeNotFoundException &) throw();
		const TypeNotFoundException &operator=(const TypeNotFoundException &) throw();
		~TypeNotFoundException() throw();
        virtual const char *what() const throw();
};

#endif