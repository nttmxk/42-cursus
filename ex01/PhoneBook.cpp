/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:42:37 by jinoh             #+#    #+#             */
/*   Updated: 2022/09/15 14:42:37 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->len = 0;
	this->last = 0;
}

void 	PhoneBook::addContact()
{
	Contact contact;
	contact.enterContact();
	this->contact[last] = contact;
	last++;
	if (last == 8)
		last = 0;
	if (len < 8)
		len++;
}

void	PhoneBook::searchContact()
{
	int	i;

	std::cout << "Enter an Index: \n";
	printBook();
	std::cin >> i;
	std::cin.ignore(); // to flush the buffer
	if (!std::cin || i < 0 || i >= len)
		std::cout << "Wrong Input!\n";
	else
		contact[i].printInfo();
}

void 	PhoneBook::printBook()
{
	int i;

	i = -1;
	std::cout << "     index" << '|' << \
	"first name" << '|' << \
	" last name" << '|' << \
	" nick name" << '|' << '\n';
	while (++i < len)
		printContact(i);
}

void	PhoneBook::printContact(int i)
{
	std::cout << "         " << i << '|';
	contact[i].printContact();
}
