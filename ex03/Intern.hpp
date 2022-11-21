#ifndef INTERN_HPP

# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>
# include <string>

class Intern {
public:
	class NoFormExistException : public std::exception{
	public:
		const char *what() const throw();
	};
	Intern();
	~Intern();
	Intern(const Intern &src);
	Intern& operator=(const Intern &src);
	Form *makeForm(const std::string &name, const std::string &target) const;
};

#endif