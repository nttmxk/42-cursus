/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:39:21 by jinoh             #+#    #+#             */
/*   Updated: 2022/09/24 01:39:22 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
