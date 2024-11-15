#ifndef FIXED
# define FIXED

#include <ostream>
class Fixed
{
	private:
		int _val;
		static const int _frac = 8;
	public:
		Fixed();
		Fixed(int const val);
		Fixed(float const val);
		Fixed(const Fixed &origin);
		const Fixed &operator=(const Fixed &other);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif