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

#include "FragTrap.hpp"

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

	FragTrap c("Patrick");

	c.attack("Steve");
	c.takeDamage(7);
	c.beRepaired(2);
	c.attack("Josh");
	c.beRepaired(4);
	c.highFivesGuys();

	return 0;
}