#include "PhoneBook.hpp"

int main(void)
{
	std::string	str;
	PhoneBook	book;

	while (1)
	{
		std::cout << "Command: ";
		std::cin >> str;
		if (str == "ADD")
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