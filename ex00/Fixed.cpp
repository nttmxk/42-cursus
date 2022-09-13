#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->value = 0;
}

Fixed::Fixed(const Fixed &orig)
{
	std::cout << "Copy constructor called\n";
	*this = orig;
}

Fixed& Fixed::operator=(const Fixed &orig)
{
	std::cout << "Copy assignment operator called\n";
	value = orig.getRawBits();
	return (*this);
}
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}