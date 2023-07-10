#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <cstring>
# include <vector>
# include <list>
# include <algorithm>
# include <exception>
# include <ctime>

class PmergeMe
{
private:
	std::vector<int>	input;
	std::vector<int>	v;
	std::list<int>		l;

	void	checkInput(const char *s);
	void 	sortVector();
	void	sortList();
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe& operator=(const PmergeMe &src);

	void	sort(int n, const char **argv);
};



#endif
