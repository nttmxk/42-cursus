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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {
	try
	{
		Bureaucrat a("Master", 1);
		Bureaucrat b("Kane", 19);
		Bureaucrat c("Son", 138);
		ShrubberyCreationForm sa("ShrubberyA");
		ShrubberyCreationForm sb("ShrubberyB");
		RobotomyRequestForm ra("RobotA");
		PresidentialPardonForm pa("PrisonerA");
		PresidentialPardonForm pb("PrisonerB");

		std::cout << sa << ra << pa;
		a.signForm(sa);
		a.signForm(ra);
		a.signForm(pa);

		b.executeForm(sa); // signed and executed
		b.executeForm(sb); // not signed and not executed
		c.executeForm(sa); // signed but not executed

		b.executeForm(ra); // signed and executed
		b.executeForm(ra);
		b.executeForm(ra);

		b.executeForm(pa); // signed but not executed
		a.executeForm(pa); // signed and executed
		a.executeForm(pb); // not signed and not executed
	}
	catch(const std::exception &e) // why reference? to avoid copy cost and not to concern allocation and free
	{
		std::cout << e.what();
	}
	return 0;
}