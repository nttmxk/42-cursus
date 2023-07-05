#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstring>
# include <sstream>

class RPN {
private:
	std::stack<int> stack;
	void	popOP(char c);

public:
	RPN();
	~RPN();
	RPN(const RPN &src);
	RPN& operator=(const RPN &src);

	void	calculate(const char *str);
};

#endif
