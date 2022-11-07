#ifndef FORM_HPP

# define FORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>
# include <exception>

class Form {
private:
	std::string const name;
	bool sign;
	const int grade_sign;
	const int grade_exec;

public:
	class GradeTooHighException : public std::exception{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
	public:
		const char *what() const throw();
	};
	Form();
	Form(std::string const &name, int grade_sign, int grade_exec);
	~Form();
	Form(const Form &src);
	Form& operator=(const Form &src);
	void beSigned(const Bureaucrat &src);
	bool getSign();
	const std::string &getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
};

std::ostream& operator<<(std::ostream& outputStream, const Form &src);


#endif
