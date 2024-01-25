/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:42:15 by jinoh             #+#    #+#             */
/*   Updated: 2022/09/15 14:42:16 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::enterContact()
{
	std::cout << "Enter Contact Info\n";

	std::cout << "Firstname: ";
	std::cin >> std::ws;
	std::getline(std::cin, firstname);

	std::cout << "Lastname: ";
	std::cin >> std::ws;
	std::getline(std::cin, lastname);

	std::cout << "Nickname: ";
	std::cin >> std::ws;
	std::getline(std::cin, nickname);

	std::cout << "Phone Number: ";
	std::cin >> std::ws;
	std::getline(std::cin, phonenum);

	std::cout << "darkest secret: ";
	std::cin >> std::ws;
	std::getline(std::cin, secret);
	if (std::cin.eof())
	{
		std::cout << "\n^D Error\n";
		exit(1);
	}
	else
		std::cout << "Created\n";
}

void 	Contact::printContact()
{
	printByFormat(firstname);
	printByFormat(lastname);
	printByFormat(nickname);
	std::cout << '\n';
}

void 	Contact::printInfo()
{
	std::cout <<
	"Firstname: " + firstname + '\n' +
	"Lastname: "+ lastname + '\n' +
	"Nickname: "+ nickname + '\n' +
	"Phone Number: "+ phonenum + '\n' +
	"Darkest Secret: "+ secret + '\n';
}

void 	Contact::printByFormat(std::string str)
{
	if (str.size() > 10)
		std::cout << str.substr(0, 9) + '.';
	else
		std::cout << std::setw(10) << str;
	std::cout << '|';
}
