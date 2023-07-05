#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstring>
# include <sstream>

class RPN {
private:
	std::stack<float>	stack;
	void	popOP(char c);
	void	pushOP(const std::string &str);
	void	checkInput(const char *s);

public:
	RPN();
	~RPN();
	RPN(const RPN &src);
	RPN& operator=(const RPN &src);

	void	calculate(const char *str);
};

#endif
