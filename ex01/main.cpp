/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:39:30 by jinoh             #+#    #+#             */
/*   Updated: 2022/09/24 01:39:31 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {

	ClapTrap a("Zion.T");

	a.setDamage(3);
	a.attack("Simon");
	a.takeDamage(7);
	a.beRepaired(2);
	a.beRepaired(2);
	a.beRepaired(2);
	a.beRepaired(5);
	a.beRepaired(5);
	a.beRepaired(2);
	a.beRepaired(2);
	a.beRepaired(2);
	a.attack("Tom");
	a.beRepaired(2);
	a.attack("Carol");

	ScavTrap b("Crush");

	b.attack("Or");
	b.takeDamage(7);
	b.beRepaired(2);
	b.attack("Monnaie");
	b.beRepaired(4);
	b.guardGate();
	b.guardGate();

	return 0;
}