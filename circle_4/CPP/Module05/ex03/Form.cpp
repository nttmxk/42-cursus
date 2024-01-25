#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("Jon Doe"), grade_sign(40), grade_exec(20), sign(false)
{
//	std::cout << "[Form] Default constructor called\n";
}

Form::Form(std::string const &name, int grade_sign, int grade_exec)
:name(name), grade_sign(grade_sign), grade_exec(grade_exec), sign(false)
{
//	std::cout << "[Form] constructor called\n";
	if (grade_sign < highestGrade || grade_exec < highestGrade)
		throw (GradeTooHighException());
	if (grade_sign > lowestGrade || grade_exec > lowestGrade)
		throw (GradeTooLowException());
}

Form::Form(const Form &src): name(src.name), grade_sign(src.getGradeSign()), grade_exec(src.getGradeExec()), sign(src.getSign())
{
//	std::cout << "[Form] Copy constructor called\n";
	*this = src;
}

Form& Form::operator=(const Form &src)
{
//	std::cout << "[Form] Copy assignment operator called\n";
	*const_cast<std::string*>(&name) = src.getName();
	sign = src.getSign();
	*const_cast<int*>(&grade_sign) = src.getGradeSign();
	*const_cast<int*>(&grade_exec) = src.getGradeExec();
	return (*this);
}

Form::~Form()
{
	std::cout << "[Form] Destructor called\n";
}

std::ostream& operator<<(std::ostream& outputStream, const Form &src)
{
	outputStream << src.getName() << ", required grade to sign is " << src.getGradeSign()
	<< ", required grade to execute is " << src.getGradeExec() << " and signed: " << std::boolalpha << src.getSign() << ".\n";
	return (outputStream);
}

const std::string &Form::getName() const
{
	return (name);
}

bool Form::getSign() const
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

void Form::beSigned(Bureaucrat &src)
{
	if (src.getGrade() <= grade_sign)
	{
		sign = true;
		std::cout << this->getName() << " got signed.\n";
	}
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Grade is Too High.\n";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Grade is Too Low.\n";
}