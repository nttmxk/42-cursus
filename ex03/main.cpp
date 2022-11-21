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
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	Bureaucrat a("Master", 1);
	Bureaucrat b("Kane", 19);
	Form *sa;
	Form *ra;
	Form *pa;
	Form *none;

	sa = someRandomIntern.makeForm("shrubbery creation", "ShrubberyA");
	ra = someRandomIntern.makeForm("robotomy request", "RobotA");
	pa = someRandomIntern.makeForm("presidential pardon", "PrisonerA");
	none = someRandomIntern.makeForm("No exist form", "whatever");

//	ShrubberyCreationForm sa("ShrubberyA");
//	RobotomyRequestForm ra("RobotA");
//	PresidentialPardonForm pa("PrisonerA");

	a.signForm(*sa);
	a.signForm(*ra);
	a.signForm(*pa);

	b.executeForm(*sa); // signed and executed
	b.executeForm(*ra); // signed and executed
	b.executeForm(*pa); // signed but not executed

	delete sa;
	delete ra;
	delete pa;

	return 0;
}