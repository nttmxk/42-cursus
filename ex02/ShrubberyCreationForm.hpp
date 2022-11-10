#ifndef SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
# include <iostream>
# include <exception>

class Bureaucrat;

class ShrubberyCreationForm: public Form {
private:
	std::string const name;
	bool sign;
	static const int grade_sign = 145;
	static const int grade_exec = 137;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &name);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &src);
	void execute(Bureaucrat const &executor) const;
};

#endif