#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10

void check_leaks()
{
	system("leaks array");
}

template <typename T>
void printArr(Array<T> &array)
{
	std::cout << "Printing Array\n";
	for (unsigned int i = 0; i < array.size(); ++i)
		std::cout << array[i] << '\n';
	std::cout << "--------------\n";
}

int main(int, char**)
{
	atexit(check_leaks);
	/////////////////////////////
	Array<char> test;
	Array<char> testWithSize(5);
	printArr(testWithSize);

	try
	{
		for (unsigned int i = 0; i < 6; ++i)
			testWithSize[i] = 'a' + i;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	printArr(testWithSize);

	std::cout << "test = testWithSize\n";
	test = testWithSize;
	std::cout << "test2(testWithSize)\n";
	Array<char> test2(testWithSize);
	std::cout << "Calling printArr...\n";
	printArr(test);
	printArr(test2);
	/////////////////////////////



	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		///////////////////////
		std::cout << "Testing in the scope\n";
//		printArr(tmp);
//		printArr(test);
		///////////////////////
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	///////////////////////
//	printArr(numbers);
//	std::cout << "Printing mirrors\n";
//	for (int i = 0; i < MAX_VAL; ++i)
//		std::cout << mirror[i] << '\n';
	///////////////////////

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	std::cout << "Test ends\n";
	delete [] mirror;//
	return 0;
}