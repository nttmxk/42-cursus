#include "Span.hpp"

void test()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void myTest()
{
	Span sp = Span(5);
}

int main()
{
	test();
//	myTest();
	return (0);
}
