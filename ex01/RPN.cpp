#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN &src){ *this = src; }
RPN& RPN::operator=(const RPN &src) {
	static_cast<void>(src);
	return (*this);
}

void	RPN::checkInput(const char *s)
{
	std::string str = s;
	std::string	valid = "0123456789+-/* ";
	size_t pos = str.find_first_not_of(valid);

	if (pos != std::string::npos)
		throw std::runtime_error("Error: unknown character");
}

void	RPN::calculate(const char *s)
{
	std::string str = s;
	size_t	prev = 0;
	size_t	next;

	while (str[prev])
	{
		next = str.find(' ', prev);
		if (next == std::string::npos) {
			popOP(str[prev]);
			break;
		}
		if (next - prev == 1 && !std::isdigit(str[prev]))
			popOP(str[prev]);
		else
			pushOP(str.substr(prev, next - prev));
		prev = next + 1;
	}

	if (prev + 1 != str.length())
		throw std::runtime_error("Error: wrong input: end");
	if (stack.size() != 1)
		throw std::runtime_error("Error: wrong input: size");
	std::cout << stack.top() << '\n';
}

void	RPN::pushOP(const std::string &str)
{
	std::string valid = "0123456789.";
	size_t pos = str.find_first_not_of(valid);

	if (pos != std::string::npos)
		throw std::runtime_error("Error: wrong input: number [npos]");

	size_t	cnt = 0;
	for (int i = 0; str[i]; ++i) {
		if (str[i] == '.')
			cnt++;
	}
	if (cnt > 1)
		throw std::runtime_error("Error: wrong input: number [.]");

	float	val;

	std::stringstream(str) >> val;
	if (val >= 10.0)
		throw std::runtime_error("Error: wrong input: number [10.0]");
	stack.push(val);
}

void	RPN::popOP(char c)
{
	float	val;

	if (stack.size() < 2)
		throw std::runtime_error("Error: pop");

	val = stack.top();
	stack.pop();

	if (c == '+')
		val += stack.top();
	else if (c == '-')
		val = stack.top() - val;
	else if (c == '/')
		val = stack.top() / val;
	else if (c == '*')
		val *= stack.top();
	else
		throw std::runtime_error("Error: unknown op");

	stack.pop();
	stack.push(val);
}