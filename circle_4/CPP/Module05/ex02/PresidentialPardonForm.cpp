#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("John Doe", grade_sign, grade_exec)
{
//	std::cout << "[PresidentialPardonForm] Default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &name): Form(name, grade_sign, grade_exec)
{
//	std::cout << "[PresidentialPardonForm] constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
		: Form(src.getName(), grade_sign, grade_exec)
{
//	std::cout << "[PresidentialPardonForm] Copy constructor called\n";
	*this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
//	std::cout << "[PresidentialPardonForm] Copy assignment operator called\n";
	*const_cast<std::string*>(&name) = src.getName();
	sign = src.getSign();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] Destructor called\n";
}

std::ostream& operator<<(std::ostream& outputStream, const PresidentialPardonForm &src)
{
	outputStream << src.getName() << ", required grade to sign is " << src.getGradeSign()
				 << ", required grade to execute is " << src.getGradeExec() << " and signed: " << std::boolalpha << src.getSign() << ".\n";
	return (outputStream);
}

int PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getSign())
	{
		std::cout << "Form "<< getName() <<" is not signed so cannot be executed.\n";
	}
	else if (executor.getGrade() > getGradeExec())
	{
		std::cout << "Executor's grade is not high enough to execute " << getName() << '\n';
	}
	else
	{
		std::cout << getName() << " has been pardoned by Zaphod Beeblebrox\n";
		return (0);
	}
	return (1);
}