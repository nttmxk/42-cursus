#include "iter.hpp"

int main( void ) {
	int i[5] = {0, 1, 2, 3, 4};
	float f[5] = {-5.5, -2.5, 0.0, 2.5, 7.5};
	char c[5] = {'a', 'b', 'c', 'd', 'e'};
	std::string s[5] = {"This", "is", "proper", "test", "cases"};

	iter(i, 5, printArr);
	iter(f, 5, printArr);
	iter(c, 5, printArr);
	iter(s, 5, printArr);

	return 0;
}