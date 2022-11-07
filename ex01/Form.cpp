#include "Form.hpp"

Form::Form(): name("Jon Doe"), grade_sign(40), grade_exec(20), sign(false)
{
	std::cout << "[Form] Default constructor called\n";
}

Form::Form(std::string const &name, int grade_sign, int grade_exec)
:name(name), grade_sign(grade_sign), grade_exec(grade_exec), sign(false)
{
	std::cout << "[Form] constructor called\n";
}

Form::Form(const Form &src)
{
	std::cout << "[Form] Copy constructor called\n";
	*this = src;
}

Form& Form::operator=(const Form &src)
{
	std::cout << "[Form] Copy assignment operator called\n";
	*const_cast<std::string*>(&name) = src.getName();
	sign = src.getSign();
	grade_sign = src.getGradeSign();
	grade_exec = src.getGradeExec();
	return (*this);
}

Form::~Form()
{
	std::cout << "[Form] Destructor called\n";
}

std::ostream& operator<<(std::ostream& outputStream, const Form &src)
{
	outputStream << src.getName() << ", required grade to sign is " << src.getGradeSign()
	<< ", required grade to execute is " << src.getGradeExec() << ".\n";
	return (outputStream);
}

const std::string &Form::getName() const
{
	return (name);
}

bool Form::getSign()
{
	return (sign);
}

int Form::getGradeSign() const
{
	return (grade_sign);
}

int Form::getGradeExec() const
{
	return (grade_exec);
}

void Form::beSigned(const Bureaucrat &src)
{
	if (sign)
	{
		std::cout << "Form is already signed.\n";
	}
	if (src.getGrade() <= grade_sign)
	{
		sign = true;
		std::cout << "Form just got signed.\n";
	}
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Bureaucrat's grade doesn't meet the required grade. It's Too High.\n";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Bureaucrat's grade doesn't meet the required grade. It's Too Low.\n";
}