#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <sstream>
# include <cstring>
# include <vector>
# include <deque>
# include <exception>
# include <ctime>
# include <utility>

# include <random>
# define ELEMENT_SIZE 5000
# define TRIAL 1

class PmergeMe
{
private:
	std::vector<int>	input;
	std::vector<int>	v;
	std::deque<int>		d;

	void				checkInput(const char *s);
	std::vector<int>	sortVector(std::vector<int>::iterator first, std::vector<int>::iterator last, int depth);
	std::deque<int>		sortDeque(std::deque<int>::iterator first, std::deque<int>::iterator last, int depth);

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe& operator=(const PmergeMe &src);
	void	sort(int n, char **argv);
	void	sortTest();
};

#endif
