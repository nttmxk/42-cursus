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