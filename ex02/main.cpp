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
#include "ShrubberyCreationForm.hpp" // do pragma once?

int main( void ) {
	try
	{
		Bureaucrat a;
		Bureaucrat b("Kane", 19);
		Bureaucrat c("Son", 38);
		ShrubberyCreationForm fa("form_a");
		ShrubberyCreationForm fb("form_b");

		std::cout << a << b << c;
		std::cout << fa << fb;
		b.signForm(fa);
		b.signForm(fb);
		c.signForm(fa);
		c.signForm(fb);
	}
	catch(const std::exception &e) // why reference? to avoid copy cost and not to concern allocation and free
	{
		std::cout << e.what();
	}
	return 0;
}