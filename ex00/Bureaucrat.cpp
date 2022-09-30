#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Jon Doe"), grade(75)
{
	std::cout << "[Bureaucrat] Default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string &name, int grade) : name(name), grade(grade)
{
	std::cout << "[Bureaucrat] constructor called\n";
	if (grade < highestGrade)
		throw (Bureaucrat::GradeTooHighException);
	if (grade > lowestGrade)
		throw (Bureaucrat::GradeTooLowException);
}


Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << "[Bureaucrat] Copy constructor called\n";
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "[Bureaucrat] Copy assignment operator called\n";
	name = src.name;
	grade = src.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] Destructor called\n";
}

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat &src)
{
	outputStream << src.getName() << ", bureaucrat grade " << src.getGrade() << ".\n";
	return (outputStream);
}

std::string Bureaucrat::getName()
{
	return (name);
}

int Bureaucrat::getGrade()
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	grade--;
	if (grade < highestGrade)
		throw (Bureaucrat::GradeTooHighException);
}

void Bureaucrat::decrementGrade()
{
	grade++;
	if (grade > lowestGrade)
		throw (Bureaucrat::GradeTooLowException);
}