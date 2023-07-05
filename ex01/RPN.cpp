#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN &src){ *this = src; }
RPN& RPN::operator=(const RPN &src) {
	static_cast<void>(src);
	return (*this);
}

void	RPN::calculate(const char *str)
{
	size_t	cnt;
	size_t	len;

	len = strlen(str);
	cnt = 0;
	for (int i = 0; str[i]; ++i) {
		if (str[i] == ' ')
			cnt++;
	}

	for (size_t i = 0; i < cnt + 1 && 2 * i <= len; ++i) {
		if (str[2 * i] >= '0' && str[2 * i] <= '9')
			stack.push(str[2 * i] - '0');
		else
			popOP(str[2 * i]);
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