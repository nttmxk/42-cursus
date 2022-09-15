/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:42:53 by jinoh             #+#    #+#             */
/*   Updated: 2022/09/15 14:42:54 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string	str;
	PhoneBook	book;

	while (1)
	{
		std::cout << "Command: ";
		std::cin >> std::ws;
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << '\n';
			std::cin.clear();
			std::clearerr(stdin);
		}
		else if (str == "ADD")
			book.addContact();
		else if (str == "SEARCH")
			book.searchContact();
		else if (str == "EXIT")
			break ;
		else
			std::cout << "Command Not Found\n";
	}
	return (0);
}
