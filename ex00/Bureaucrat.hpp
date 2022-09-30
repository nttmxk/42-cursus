#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat {
private:
	std::string const name;
	int grade;
	static const int highestGrade = 1;
	static const int lowestGrade = 150;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat& operator=(const Bureaucrat &src);
	std::string getName();
	int getGrade();
	void incrementGrade();
	void decrementGrade();
};

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat &src);

#endif
