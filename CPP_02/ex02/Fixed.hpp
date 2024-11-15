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
		bool operator<(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed operator++();
		Fixed operator++(int mock);
		Fixed operator--();
		Fixed operator--(int mock);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);


#endif