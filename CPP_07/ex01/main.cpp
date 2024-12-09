#include "iter.hpp"
#include <cctype>
#include <iostream>

class Awesome
{
	public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
	private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) 
{ 
	o << rhs.get(); return o; 
}

template< typename T >
void print(T const &x) 
{
	std::cout << x << std::endl; return; 
}

void print_inc(int const &i)
{
	std::cout << "NUM: " << i + 1 << std::endl;
}

void print_str(std::string const &str)
{
	std::string upper = str;
	for (unsigned long i = 0; i < str.length(); i++) 
	{
		upper[i] = std::toupper(str[i]);
    }
	std::cout <<"STR: " << upper << std::endl;
}

int main()
{
	int nums[] = {
		1,
		2,
		3,
		4
	};

	std::string strs[] = {
		"Hello",
		"World"
	};

	iter(nums, 4, print_inc);
	iter(strs, 2, print_str);

	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];
	iter( tab, 5, print );
	iter( tab2, 5, print );


	return 0;
}