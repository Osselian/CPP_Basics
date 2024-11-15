#ifndef FIXED
# define FIXED

class Fixed
{
	private:
		int _val;
		static const int _frac = 8;
	public:
		Fixed();
		Fixed(const Fixed &origin);
		const Fixed &operator=(const Fixed &other);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif