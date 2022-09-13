#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
private:
	int value;
	static const int fract = 8;

public:
	Fixed();
	Fixed(const Fixed &orig);
	Fixed& operator=(const Fixed &orig);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif