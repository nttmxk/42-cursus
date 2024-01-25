/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:40:53 by jinoh             #+#    #+#             */
/*   Updated: 2022/09/24 01:40:54 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
	int value;
	static const int fract = 8;

public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &orig);
	Fixed& operator=(const Fixed &orig);
	~Fixed();
	int		getRawBits(void) const;

	float	toFloat(void) const;
	int		toInt(void) const;
	void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& outputStream, const Fixed &fixed);

#endif
