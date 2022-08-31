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

	std::cout << "Enter an Index: ";
	std::cin >> i;
	if (!std::cin || i < 0 || i >= len)
		std::cout<< "Wrong Input!\n";
	else
	{
		printBook();
		printContact(i);
	}
}

void 	PhoneBook::printBook()
{
	int i;

	i = -1;
	std::cout << std::setw(10) << "index" << '|' << \
		std::setw(10) << "first name" << '|' << \
		std::setw(10) << "last name" << '|' << \
		std::setw(10) << "nick name" << '|' << '\n';
	while (++i < len)
		printContact(i);
}

void	PhoneBook::printContact(int i)
{
	std::cout << std::setw(10) << i << '|';
	contact[i].printContact();
}
