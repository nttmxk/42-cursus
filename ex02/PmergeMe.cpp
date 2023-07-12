#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &src){ *this = src; }
PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
	static_cast<void>(src);
	return (*this);
}

/*
 * 	1. 빈 문자열
 * 	2. INT 범위초과 -> 알아서저장, 신경 X
 * 	3. 0 또는 음수
 */
void	PmergeMe::checkInput(const char *s)
{
	std::string str = s;
	std::string valid = "0123456789";
	size_t		pos = str.find_first_not_of(valid);
	int			val;

	if (pos != std::string::npos)
		throw std::runtime_error("Error: wrong input: number");

	std::stringstream(str) >> val;
	input.push_back(val);
}

void	PmergeMe::sort(int n, const char **argv)
{
	int i;

	i = 0;
	while (++i <= n)
		checkInput(argv[i]);


}

void 	PmergeMe::sortVector()
{

}

