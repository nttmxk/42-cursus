#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN &src){ *this = src; }
RPN& RPN::operator=(const RPN &src) {
	return (*this);
}

void	RPN::calculate(const char *str)
{
	size_t	cnt;
	size_t	len;
	int 	val;

	len = strlen(str);
	cnt = 0;
	for (int i = 0; str[i]; ++i) {
		if (str[i] == ' ')
			cnt++;
	}

	for (int i = 0; i < cnt && 2 * i <= len; ++i) {
		if (str[2 * i] > '0' && str[2 * i] < '9')
		{
			std::stringstream(str[i]) >> val;
			stack.push(val);
		}
		else
			popOP(c);
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error");
	std::cout << stack.top() << '\n';
}

void	RPN::popOP(char c)
{
	int val;

	if (stack.size() < 2)
		throw std::runtime_error("Error: pop");

	val = stack.top();
	stack.pop();
	if (c == '+')
	{
		val += stack.top();
		stack.pop();
		stack.push(val);
	}
	else if (c == '-')
	{
		val -= stack.top();
		stack.pop();
		stack.push(val);
	}
	else if (c == '/')
	{
		val /= stack.top();
		stack.pop();
		stack.push(val);
	}
	else if (c == '*')
	{
		val *= stack.top();
		stack.pop();
		stack.push(val);
	}
	else
		throw std::runtime_error("Error: unknown op");
}