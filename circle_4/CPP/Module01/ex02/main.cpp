#include <iostream>

int main()
{
	std::string greeting = "HI THIS IS BRAIN";
	std::string *stringPTR = &greeting;
	std::string &stringREF = greeting;

	std::cout << "The memory address of the string variable: " << &greeting << '\n';
	std::cout << "The memory address held by stringPTR: " << stringPTR << '\n';
	std::cout << "The memory address held by stringREF: " << &stringREF << '\n';

	std::cout << "The value of the string variable: " << greeting << '\n';
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << '\n';
	std::cout << "The value pointed to by stringREF: " << stringREF << '\n';

	return (0);
}