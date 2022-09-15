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
	std::cin >> firstname;
	std::cout << "Lastname: ";
	std::cin >> lastname;
	std::cout << "Nickname: ";
	std::cin >> nickname;
	std::cout << "Phone Number: ";
	std::cin >> phonenum;
	std::cout << "darkest secret: ";
	std::cin >> secret;
	std::cout << "Created\n";
}

void 	Contact::printContact()
{
	printByFormat(firstname);
	printByFormat(lastname);
	printByFormat(nickname);
	std::cout << '\n';
}

void 	Contact::printByFormat(std::string str)
{
	if (str.size() > 10)
		std::cout << str.substr(0, 9) + '.';
	else
		std::cout << std::setw(10) << str;
	std::cout << '|';
}
