#include "Intern.hpp"

Form *Intern::makeForm(std::string const &name, std::string const &target) const
{
	std::string	formlist[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	std::string	*indexptr;
	int 		index;

	indexptr = find(formlist, formlist + 3, name);
	index = indexptr - formlist;
	try
	{
		switch (index)
		{
			case 0:
				return new ShrubberyCreationForm(target);
			case 1:
				return new RobotomyRequestForm(target);
			case 2:
				return new PresidentialPardonForm(target);
		}
		throw NoFormExistException();
	}
	catch(const std::exception &e) {
		std::cout << e.what();
	}
	return (nullptr);
}

Intern::Intern()
{
//	std::cout << "[Intern] Default constructor called\n";
}

Intern::Intern(const Intern &src)
{
//	std::cout << "[Intern] Copy constructor called\n";
	*this = src;
}

Intern& Intern::operator=(const Intern &src)
{
//	std::cout << "[Intern] Copy assignment operator called\n";
	static_cast<void>(src);
	return (*this);
}

Intern::~Intern()
{
	std::cout << "[Intern] Destructor called\n";
}

const char* Intern::NoFormExistException::what(void) const throw()
{
	return "No such name exists\n";
}
