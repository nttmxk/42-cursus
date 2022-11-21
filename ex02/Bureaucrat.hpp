#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>

class Form;

class Bureaucrat {
private:
	std::string const name;
	int grade;
	static const int highestGrade = 1;
	static const int lowestGrade = 150;

public:
	class GradeTooHighException : public std::exception{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
	public:
		const char *what() const throw();
	};
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat& operator=(const Bureaucrat &src);
	void signForm(Form &src);
	const std::string &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void executeForm(Form const &form);
};

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat &src);

#endif
