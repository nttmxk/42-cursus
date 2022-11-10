#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): name("Jon Doe"), sign(false)
{
//	std::cout << "[ShrubberyCreationForm] Default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &name): name(name), sign(false)
{
//	std::cout << "[ShrubberyCreationForm] constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
: name(src.name), sign(src.getSign())
{
//	std::cout << "[ShrubberyCreationForm] Copy constructor called\n";
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
//	std::cout << "[ShrubberyCreationForm] Copy assignment operator called\n";
	*const_cast<std::string*>(&name) = src.getName();
	sign = src.getSign();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] Destructor called\n";
}

std::ostream& operator<<(std::ostream& outputStream, const ShrubberyCreationForm &src)
{
	outputStream << src.getName() << ", required grade to sign is " << src.getGradeSign()
				 << ", required grade to execute is " << src.getGradeExec() << " and signed: " << std::boolalpha << src.getSign() << ".\n";
	return (outputStream);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getSign())
	{
		std::cout << "Form is not signed so cannot execute.\n";
	}
	else if (executor.getGrade() > getGradeExec())
	{
		std::cout << "Executor's grade is not high enough/\n";
	}
	else
	{
		// execute
	}
}