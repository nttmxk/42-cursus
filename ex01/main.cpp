#include "Span.hpp"

void test()
{
	Span sp = Span(5);

    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what();
    }
}

void myTest()
{
    std::vector<int> v;

    std::srand(std::time(NULL));
    for (int i = 0; i < 20; ++i)
        v.push_back(rand() % 1000);

    Span sp = Span(20);
    try {
        sp.addNumber(v.begin(), v.end());

        std::cout << sp.shortestSpan() << '\n';
        std::cout << sp.longestSpan() << '\n';
    } catch (std::exception &e) {
        std::cerr << e.what();
    }
}

void myTest2()
{
    std::vector<int> v;

    std::srand(std::time(NULL));
    for (int i = 0; i < 14242; ++i)
        v.push_back(rand());

    Span sp = Span(14242);
    try {
        sp.addNumber(v.begin(), v.end());

        std::cout << sp.shortestSpan() << '\n';
        std::cout << sp.longestSpan() << '\n';
    } catch (std::exception &e) {
        std::cerr << e.what();
    }
}

int main()
{
//	test();
	myTest();
    myTest2();
	return (0);
}
