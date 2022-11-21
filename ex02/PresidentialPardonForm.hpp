#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include <iostream>

class Bureaucrat;

class PresidentialPardonForm: public Form {
private:
	std::string const name;
	bool sign;
	static const int grade_sign = 25;
	static const int grade_exec = 5;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const &name);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &src);
	int execute(Bureaucrat const &executor) const;
};

#endif
