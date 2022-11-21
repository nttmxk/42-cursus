#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <iostream>
# include <random>

class Bureaucrat;

class RobotomyRequestForm: public Form {
private:
	std::string const name;
	bool sign;
	static const int grade_sign = 72;
	static const int grade_exec = 45;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &name);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &src);
	int execute(Bureaucrat const &executor) const;
};

#endif
