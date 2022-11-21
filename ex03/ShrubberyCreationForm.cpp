#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("John Doe", grade_sign, grade_exec)
{
//	std::cout << "[ShrubberyCreationForm] Default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &name): Form(name, grade_sign, grade_exec)
{
//	std::cout << "[ShrubberyCreationForm] constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
: Form(src.getName(), grade_sign, grade_exec)
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

int ShrubberyCreationForm::execute(Bureaucrat const &executor) const
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
		std::ofstream ofs;
		ofs.open(getName());
		if (ofs.fail())
		{
			std::cout << "File create error\n";
			return (1);
		}
		ofs << "           *             ,\n"
			   "                       _/^\\_\n"
			   "                      <     >\n"
			   "     *                 /.-.\\         *\n"
			   "              *        `/&\\`                   *\n"
			   "                      ,@.*;@,\n"
			   "                     /_o.I %_\\    *\n"
			   "        *           (`'--:o(_@;\n"
			   "                   /`;--.,__ `')             *\n"
			   "                  ;@`o % O,*`'`&\\\n"
			   "            *    (`'--)_@ ;o %'()\\      *\n"
			   "                 /`;--._`''--._O'@;\n"
			   "                /&*,()~o`;-.,_ `\"\"`)\n"
			   "     *          /`,@ ;+& () o*`;-';\\\n"
			   "               (`\"\"--.,_0 +% @' &()\\\n"
			   "               /-.,_    ``''--....-'`)  *\n"
			   "          *    /@%;o`:;'--,.__   __.'\\\n"
			   "              ;*,&(); @ % &^;~`\"`o;@();         *\n"
			   "              /(); o^~; & ().o@*&`;&%O\\\n"
			   "              `\"=\"==\"\"==,,,.,=\"==\"===\"`\n"
			   "           __.----.(\\-''#####---...___...-----._\n"
			   "         '`         \\)_`\"\"\"\"\"`\n"
			   "                 .--' ')\n"
			   "               o(  )_-\\\n"
			   "                 `\"\"\"` `\n"
			   "\n";
		ofs.close();
		std::cout << getName() << " is executed\n";
		return (0);
	}
	return (1);
}