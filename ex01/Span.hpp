#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span {
private:
	unsigned int		N;
	std::vector<int>	v;

public:
	Span();
	Span(unsigned int N);
	~Span();
	Span(const Span &orig);
	Span& operator=(const Span &orig);
	void			addNumber(int n);

	template<typename Iter>
	void 			addNumber(Iter begin, Iter end)
	{
		if (N < v.size() + end - begin)
			throw (NoSpaceException());
		v.insert(v.end(), begin, end);
	}

	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	class NoSpaceException: public std::exception {
	public:
		const char *what() throw();
	};

	class NoSpanException: public std::exception {
	public:
		const char *what() throw();
	};
};

#endif