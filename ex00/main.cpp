/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:40:59 by jinoh             #+#    #+#             */
/*   Updated: 2022/09/24 01:41:00 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void ) {
	try
	{
		Bureaucrat a;
		Bureaucrat b("Kane", 2);
		Bureaucrat c("Son", 149);

		std::cout << a << b << c;
		b.incrementGrade();
		b.decrementGrade();
		b.incrementGrade();
		c.decrementGrade();
		c.decrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	return 0;
}