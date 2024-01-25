#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &src){ *this = src; }
PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
	static_cast<void>(src);
	return (*this);
}

template<class T>
void printC(T t)
{
	size_t range;
	bool flag = false;
	if (t.size() > 10)
	{
		range = 10;
		flag = true;
	}
	else
		range = t.size();
	for (size_t i = 0; i < range; ++i) {
		std::cout << t.at(i) << ' ';
	}
	if (flag)
		std::cout << "[...]";
	std::cout << '\n';
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

void 	PmergeMe::sortTest()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 100000); // element range

	/////////////////// many tests
	for (int trial = 0; trial < TRIAL; trial++) {
		int elem_cnt = 0;
		for (; elem_cnt < ELEMENT_SIZE; elem_cnt++) {
			for (int i = 0; i < elem_cnt; i++) {
				int n = dis(gen);
				v.push_back(n);
				d.push_back(n);
			}
			v = sortVector(v.begin(), v.end(), 1);
			d = sortDeque(d.begin(), d.end(), 1);
			if (!std::is_sorted(v.begin(), v.end()) ||
				!std::is_sorted(d.begin(), d.end())) {
				std::cout << "Error with " << elem_cnt << " elements, " << trial << " trial" << std::endl;
				v.clear();
				d.clear();
			} else
			{
//				std::cout << "Good with " << elem_cnt << " elements, " << trial << " trial" << std::endl;
			}
			v.clear();
			d.clear();
		}
	}
}

void	PmergeMe::sort(int n, char **argv)
{
	int i;
	clock_t start, end;

	i = 0;
	while (++i <= n)
		checkInput(argv[i]);

	std::cout << "Before:	";
	printC(input);
	v = input;
	d.assign(input.begin(), input.end());

	start = clock();
	v = sortVector(v.begin(), v.end(), 1);
	if (!std::is_sorted(v.begin(), v.end()))
		throw std::runtime_error("Error: vector_is_not_sorted");
	end = clock();
	std::cout << "After:	";
	printC(v);
	std::cout << "Time to process a range of " << n << " elements with std::vector : " << (double)(end - start) << " ms\n";

	start = clock();
	d = sortDeque(d.begin(), d.end(), 1);
	if (!std::is_sorted(d.begin(), d.end()))
		throw std::runtime_error("Error: deque_is_not_sorted");
	end = clock();
	std::cout << "Time to process a range of " << n << " elements with std::deque  : " << (double)(end - start) << " ms\n";
}

std::vector<int> PmergeMe::sortVector(std::vector<int>::iterator first, std::vector<int>::iterator last, int depth)
{
	static unsigned int jacobsthal_diff[] = {
			2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
			2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
			1398102u, 2796202u, 5592406u, 11184810u
	};

	int step = (int) pow(2, depth - 1);
	size_t size = std::distance(first, last) / step;
	if (size < 2) {
		std::vector<int> ret(first, last);
		return ret;
	}

	bool has_stray = std::distance(first, last) % (step * 2);
	std::vector<int>::iterator end = has_stray ? (first + (int) (size - 1) * step) : last;

	for (std::vector<int>::iterator it = first; it != end; it += 2 * step) {
		if (*(it + step * 2 - 1) < *(it + step - 1)) {
			for (std::vector<int>::iterator j = it; j != it + step; j++) {
				std::iter_swap(j, j + step);
			}
		}
	}

	std::vector<int> a = sortVector(first, end, depth + 1);
	if (has_stray) {
		while (end != last) {
			a.push_back(*end);
			++end;
		}
	}
	first = a.begin();
	last = a.end();
	end = has_stray ? (first + (int) (size - 1) * step) : last;

	std::vector<int> ret;
	std::vector<int> chain;
	std::vector<int> pend;

	// first two should be in main chain
	chain.push_back(*(first + step - 1));
	chain.push_back(*(first + step * 2 - 1));
	ret.insert(ret.begin(), first, first + step * 2);

	for (std::vector<int>::iterator it = first + 2 * step; it != end; it += 2 * step) {
		chain.push_back(*(it + step * 2 - 1));
		ret.insert(ret.end(), it + step, it + step * 2);
		pend.push_back(*(it + step - 1));
	}

	std::vector<int>::iterator curr_it = chain.begin() + 1;
	std::vector<int>::iterator curr_pend = pend.begin();

	for (int idx = 0;; ++idx) {
		int flagCount = 0;
		int dist = jacobsthal_diff[idx];
		if (dist > std::distance(curr_pend, pend.end()))
			break;
		curr_it += dist;
		curr_pend += dist;
		int i = 0;
		while (i++ < dist) {
			bool flag = false;
			--curr_pend;

			std::vector<int>::iterator insert_point = std::upper_bound(chain.begin(), curr_it, *curr_pend);
			if (insert_point == curr_it)
			{
				++flagCount;
				flag = true;
			}

			int regI = std::distance(chain.begin(), curr_it);
			int distR = std::distance(chain.begin(), insert_point);
			chain.insert(insert_point, *curr_pend);
			///////////// curr_it is changed to weird value after chain insert
			if (flag)
				curr_it = chain.begin() + regI - 1;
			else
				curr_it = chain.begin() + regI;
			int distP = std::distance(pend.begin(), curr_pend) + 1;
			ret.insert(ret.begin() + distR * step, first + distP * step * 2, first + distP * step * 2 + step);
		}
		curr_it += dist + flagCount;
		curr_pend += dist;
	}

	while (curr_pend != pend.end()) {
		std::vector<int>::iterator insert_point = std::upper_bound(chain.begin(), chain.end(), *curr_pend);
		int distR = std::distance(chain.begin(), insert_point);
		chain.insert(insert_point, *curr_pend);
		int distP = std::distance(pend.begin(), curr_pend) + 1;
		ret.insert(ret.begin() + distR * step, first + distP * step * 2, first + distP * step * 2 + step);
		++curr_pend;
	}
	// insert (end + step - 1) into mainChain and follow the main logic
	if (has_stray) {
		std::vector<int>::iterator insert_point = std::upper_bound(chain.begin(), chain.end(), *(end + step - 1));
		int distR = std::distance(chain.begin(), insert_point);
		ret.insert(ret.begin() + distR * step, end, end + step);
	}
	return ret;
}

std::deque<int>	PmergeMe::sortDeque(std::deque<int>::iterator first, std::deque<int>::iterator last, int depth)
{
	static unsigned int jacobsthal_diff[] = {
			2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
			2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
			1398102u, 2796202u, 5592406u, 11184810u
	};

	int step = (int) pow(2, depth - 1);
	size_t size = std::distance(first, last) / step;
	if (size < 2) {
		std::deque<int> ret(first, last);
		return ret;
	}

	bool has_stray = std::distance(first, last) % (step * 2);
	std::deque<int>::iterator end = has_stray ? (first + (int) (size - 1) * step) : last;

	for (std::deque<int>::iterator it = first; it != end; it += 2 * step) {
		if (*(it + step * 2 - 1) < *(it + step - 1)) {
			for (std::deque<int>::iterator j = it; j != it + step; j++) {
				std::iter_swap(j, j + step);
			}
		}
	}

	std::deque<int> a = sortDeque(first, end, depth + 1);
	if (has_stray) {
		while (end != last) {
			a.push_back(*end);
			++end;
		}
	}
	first = a.begin();
	last = a.end();
	end = has_stray ? (first + (int) (size - 1) * step) : last;

	std::deque<int> ret;
	std::deque<int> chain;
	std::deque<int> pend;

	chain.push_back(*(first + step - 1));
	chain.push_back(*(first + step * 2 - 1));
	ret.insert(ret.begin(), first, first + step * 2);

	for (std::deque<int>::iterator it = first + 2 * step; it != end; it += 2 * step) {
		chain.push_back(*(it + step * 2 - 1));
		ret.insert(ret.end(), it + step, it + step * 2);
		pend.push_back(*(it + step - 1));
	}

	std::deque<int>::iterator curr_it = chain.begin() + 1;
	std::deque<int>::iterator curr_pend = pend.begin();

	for (int idx = 0;; ++idx) {
		int flagCount = 0;
		int dist = jacobsthal_diff[idx];
		if (dist > std::distance(curr_pend, pend.end()))
			break;
		curr_it += dist;
		curr_pend += dist;
		int i = 0;
		while (i++ < dist) {
			bool flag = false;
			--curr_pend;

			std::deque<int>::iterator insert_point = std::upper_bound(chain.begin(), curr_it, *curr_pend);
			if (insert_point == curr_it)
			{
				++flagCount;
				flag = true;
			}

			int regI = std::distance(chain.begin(), curr_it);
			int distR = std::distance(chain.begin(), insert_point);
			chain.insert(insert_point, *curr_pend);
			if (flag)
				curr_it = chain.begin() + regI - 1;
			else
				curr_it = chain.begin() + regI;
			int distP = std::distance(pend.begin(), curr_pend) + 1;
			ret.insert(ret.begin() + distR * step, first + distP * step * 2, first + distP * step * 2 + step);
		}
		curr_it += dist + flagCount;
		curr_pend += dist;
	}

	while (curr_pend != pend.end()) {
		std::deque<int>::iterator insert_point = std::upper_bound(chain.begin(), chain.end(), *curr_pend);
		int distR = std::distance(chain.begin(), insert_point);
		chain.insert(insert_point, *curr_pend);
		int distP = std::distance(pend.begin(), curr_pend) + 1;
		ret.insert(ret.begin() + distR * step, first + distP * step * 2, first + distP * step * 2 + step);
		++curr_pend;
	}
	if (has_stray) {
		std::deque<int>::iterator insert_point = std::upper_bound(chain.begin(), chain.end(), *(end + step - 1));
		int distR = std::distance(chain.begin(), insert_point);
		ret.insert(ret.begin() + distR * step, end, end + step);
	}
	return ret;
}