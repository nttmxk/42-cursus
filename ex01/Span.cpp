#include "Span.hpp"

Span::Span() {
	N = 10;
}

Span::Span(unsigned int N) {
	this->N = N;
}

Span::Span(const Span &orig) {
	N = orig.N;
	v = orig.v;
}

Span& Span::operator=(const Span &orig) {
	if (this != &orig) {
		N = orig.N;
		v = orig.v;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int n) {
	if (N == v.size())
		throw NoSpaceException();
	v.push_back(n);
}

unsigned int 	Span::shortestSpan() {
	if (v.size() < 2)
		throw NoSpanException();
	std::vector<int> tmp = v;
	std::sort(tmp.begin(), tmp.end());
	unsigned int shortest = *(tmp.begin() + 1) - *tmp.begin();
	for (std::vector<int>::iterator i = tmp.begin() + 1; i < tmp.end() - 1; i++) {
		if ((unsigned int)(*(i + 1) - *i) < shortest)
			shortest = *(i + 1) - *i;
	}
	return (shortest);
}

unsigned int 	Span::longestSpan() {
	if (v.size() < 2)
		throw NoSpanException();
	return (*std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end()));
}

const char *Span::NoSpaceException::what() const throw() {
	return "No Space Exception\n";
}


const char *Span::NoSpanException::what() const throw() {
	return "No Span Exception\n";
}