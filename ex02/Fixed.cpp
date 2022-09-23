/* ************************************************************************** *//*                                                                            *//*                                                        :::      ::::::::   *//*   Fixed.cpp                                          :+:      :+:    :+:   *//*                                                    +:+ +:+         +:+     *//*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        *//*                                                +#+#+#+#+#+   +#+           *//*   Created: 2022/09/24 01:40:47 by jinoh             #+#    #+#             *//*   Updated: 2022/09/24 01:40:48 by jinoh            ###   ########.fr       *//*                                                                            *//* ************************************************************************** */#include "Fixed.hpp"Fixed::Fixed(){//	std::cout << "Default constructor called\n";	this->value = 0;}Fixed::Fixed(const int n){//	std::cout << "Int constructor called\n";	this->value = n << fract;}Fixed::Fixed(const float n){//	std::cout << "Float constructor called\n";	this->value = roundf(n * (1 << fract));}Fixed::Fixed(const Fixed &orig){//	std::cout << "Copy constructor called\n";	*this = orig;}Fixed& Fixed::operator=(const Fixed &orig){//	std::cout << "Copy assignment operator called\n";	value = orig.getRawBits();	return (*this);}std::ostream& operator<<(std::ostream& outputStream, const Fixed &fixed){	outputStream << fixed.toFloat();	return (outputStream);}bool operator>(const Fixed &a, const Fixed &b){	return (a.getRawBits() > b.getRawBits());}bool operator<(const Fixed &a, const Fixed &b){	return (a.getRawBits() < b.getRawBits());}bool operator>=(const Fixed &a, const Fixed &b){	return (a.getRawBits() >= b.getRawBits());}bool operator<=(const Fixed &a, const Fixed &b){	return (a.getRawBits() <= b.getRawBits());}bool operator==(const Fixed &a, const Fixed &b){	return (a.getRawBits() == b.getRawBits());}bool operator!=(const Fixed &a, const Fixed &b){	return (a.getRawBits() != b.getRawBits());}Fixed operator+(const Fixed &a, const Fixed &b){	return (Fixed(a.toFloat() + b.toFloat()));}Fixed operator-(const Fixed &a, const Fixed &b){	return (Fixed(a.toFloat() - b.toFloat()));}Fixed operator*(const Fixed &a, const Fixed &b){	return (Fixed(a.toFloat() * b.toFloat()));}Fixed operator/(const Fixed &a, const Fixed &b){	return (Fixed(a.toFloat() / b.toFloat()));}Fixed& Fixed::operator++() // prefix operator{//	std::cout << "prefix increment" << '\n';	this->setRawBits(this->getRawBits() + 1);	return (*this);}Fixed Fixed::operator++(int) // postfix operator{//	std::cout << "postfix increment" << '\n';	Fixed temp = *this;	this->setRawBits(this->getRawBits() + 1);	return (temp);}Fixed& Fixed::operator--(){	this->setRawBits(this->getRawBits() - 1 );	return (*this);}Fixed Fixed::operator--(int){	Fixed temp = *this;	this->setRawBits(this->getRawBits() - 1);	return (temp);}Fixed& Fixed::min(Fixed &a, Fixed &b){	if (a < b)		return (a);	return (b);}const Fixed& Fixed::min(const Fixed &a, const Fixed &b){	if (a < b)		return (a);	return (b);}Fixed& Fixed::max(Fixed &a, Fixed &b){	if (a > b)		return (a);	return (b);}const Fixed& Fixed::max(const Fixed &a, const Fixed &b){	if (a > b)		return (a);	return (b);}Fixed::~Fixed(){//	std::cout << "Destructor called\n";}int Fixed::getRawBits(void) const{//	std::cout << "getRawBits member function called\n";	return (this->value);}void Fixed::setRawBits(int const raw){	this->value = raw;}float Fixed::toFloat(void) const{	float	n;	n = float(this->value) / (1 << fract);	return (n);}int Fixed::toInt(void) const{	int	n;	n = this->value >> fract;	return (n);}