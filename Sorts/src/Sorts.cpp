#include <iostream>
#include <cstdlib>
#include <assert.h>
#include "Sorts.h"

template <class T, class A>
void printArray(const std::vector<T, A>& array)
{
	for (typename std::vector<int>::const_iterator pos = array.begin(); pos != array.end(); ++pos)
		std::cout << *pos << " ";
	std::cout << std::endl;
}

template <class T, class A>
bool isSorted(const std::vector<T, A>& array)
{
	typename std::vector<int>::const_iterator pos = array.begin();
	T pr = *pos, next;
	++pos;
	while (pos != array.end())
	{
		next = *pos;
		if (next < pr)
			return false;
		pr = next;
		++pos;
	}
	return true;
}

void RandomTest()
{
	bool print = false;
	std::cout << "Input the size of random array." << std::endl;
	std::size_t size;
	std::cin >> size; // add exception
	assert(size > 0);
	std::vector<int> input(size);
	for (std::vector<int>::iterator pos = input.begin(); pos != input.end(); ++pos)
		*pos = std::rand();
	if (size < 10000)
	{
		std::vector<int> input1(input);
		if (print) std::cout << "Before: ";
		if (print) printArray(input1);
		std::cout << "Selection sort: ";
		selectionSort(input1);
		if (isSorted(input1))
		{
			if (print) printArray(input1);
			else std::cout << "Write sort)" << std::endl;
		}
		else
			std::cout << "Wrong order!" << std::endl;

		std::vector<int> input2(input);
		if (print) std::cout << "Before: ";
		if (print) printArray(input2);
		std::cout << "Insertion sort: ";
		insertionSort(input2);
		if (isSorted(input2))
		{
			if (print) printArray(input2);
			else std::cout << "Write sort)" << std::endl;
		}
		else
			std::cout << "Wrong order!" << std::endl;
	}

	std::vector<int> input4(input);
	if (print) std::cout << "Before: ";
	if (print) printArray(input4);
	std::cout << "Merge sort: ";
	mergeSort(input4);
	if (isSorted(input4))
	{
		if (print) printArray(input4);
		else std::cout << "Write sort)" << std::endl;
	}
	else
		std::cout << "Wrong order!" << std::endl;

	std::vector<int> input5(input);
	if (print) std::cout << "Before: ";
	if (print) printArray(input5);
	std::cout << "Quick sort: ";
	quickSort(input5);
	if (isSorted(input5))
	{
		if (print) printArray(input5);
		else std::cout << "Write sort)" << std::endl;
	}
	else
		std::cout << "Wrong order!" << std::endl;
}

void intersectionOfTwoSets()
{
	int myintsa[] = {1, 4, 2, 3, 8, 5, 6, 7, 0, 9};
	std::vector<int> one(myintsa, myintsa + sizeof(myintsa) / sizeof(int));
	int myintsb[] = {6, 8, 0, 2, 4};
	std::vector<int> two(myintsb, myintsb + sizeof(myintsb) / sizeof(int));
	quickSort(one);
	quickSort(two);
	int answer = 0;
	for (std::vector<int>::const_iterator i = one.begin(), j = two.begin(); i != one.end(), j != two.end();)
	{
		if (*i > *j) ++j;
		else if (*i < *j) ++i;
		else
		{
			answer++;
			i++;
			j++;
		}
	}
	std::cout << answer;
}

void permutation()
{
	int myintsa[] = {6, 4, 0, 2, 8, 8};
	std::vector<int> one(myintsa, myintsa + sizeof(myintsa) / sizeof(int));
	int myintsb[] = {6, 8, 0, 2, 4, 8};
	std::vector<int> two(myintsb, myintsb + sizeof(myintsb) / sizeof(int));
	quickSort(one);
	quickSort(two);
	if (one == two)
		std::cout << "Permutation!";
	else
		std::cout << "Not permutation!";
}

int main()
{
	permutation();
	return 0;
}
