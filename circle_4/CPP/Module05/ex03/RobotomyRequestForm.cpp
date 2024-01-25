#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("John Doe", grade_sign, grade_exec)
{
//	std::cout << "[RobotomyRequestForm] Default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &name): Form(name, grade_sign, grade_exec)
{
//	std::cout << "[RobotomyRequestForm] constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
		: Form(src.getName(), grade_sign, grade_exec)
{
//	std::cout << "[RobotomyRequestForm] Copy constructor called\n";
	*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
//	std::cout << "[RobotomyRequestForm] Copy assignment operator called\n";
	*const_cast<std::string*>(&name) = src.getName();
	sign = src.getSign();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] Destructor called\n";
}

std::ostream& operator<<(std::ostream& outputStream, const RobotomyRequestForm &src)
{
	outputStream << src.getName() << ", required grade to sign is " << src.getGradeSign()
				 << ", required grade to execute is " << src.getGradeExec() << " and signed: " << std::boolalpha << src.getSign() << ".\n";
	return (outputStream);
}

int RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 1);

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
		std::cout << "[Drilling noises]\n" << getName();
		if (dis(gen))
			std::cout << " has been robotomized successfully\n";
		else
			std::cout << " robotomized has been failed\n";
		return (0);
	}
	return (1);
}