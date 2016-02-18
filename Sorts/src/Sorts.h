#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include <iterator>

template <class T, class A>
void selectionSort(std::vector<T, A>& array)
{
	typedef typename std::vector<T, A>::iterator iterator;
	for (iterator i = array.begin(); i != array.end(); ++i)
	{
		iterator min = i;
		for (iterator j = i + 1; j != array.end(); ++j)
			if (*j < *min)
				min = j;
		std::swap(*i, *min);
	}
}


template <class T, class A>
void insertionSort(std::vector<T, A>& array, int step = 1)
{
	typedef typename std::vector<T, A>::iterator iterator;
	for (iterator i = array.begin(); i != array.end(); ++i)
	{
		iterator j = i;
		while (array.begin() < j && *(j-1) > *j)
		{
			std::swap(*j, *(j-1));
			j = j - step;
		}
	}
}

template <class T, class A>
void merge(std::vector<T, A>& array, typename std::vector<T, A>::iterator lo, typename std::vector<T, A>::iterator mid, typename std::vector<T, A>::iterator hi)
{
	typedef typename std::vector<T, A>::iterator iterator;
	std::vector<T, A> aux1(lo, mid);
	std::vector<T, A> aux2(mid, hi);
	iterator i = aux1.begin();
	iterator j = aux2.begin();
	iterator k = lo;
	while (i != aux1.end() && j != aux2.end())
	{
		if (*j < *i)
		{
			*k = *j;
			++j;
		}
		else
		{
			*k = *i;
			++i;
		}
		++k;
	}
	if (j == aux2.end())
		while (i != aux1.end())
		{
			*k = *i;
			++i;
			++k;
		}
	else
		while (j != aux2.end())
		{
			*k = *j;
			++j;
			++k;
		}
}

template <class T, class A>
void sortMerge(std::vector<T, A>& array, typename std::vector<T, A>::iterator lo, typename std::vector<T, A>::iterator hi)
{
	if (hi - lo == 1) return;
	typename std::vector<T, A>::iterator mid = lo + (int)(hi-lo)/2;
	sortMerge(array, lo, mid);
	sortMerge(array, mid, hi);
	merge(array, lo, mid, hi);
}

template <class T, class A>
void mergeSort(std::vector<T, A>& array)
{
	typename std::vector<T, A>::iterator begin = array.begin();
	typename std::vector<T, A>::iterator end = array.end();
	sortMerge(array, begin, end);
}

template <class T, class A>
int partition(std::vector<T, A>& array, typename std::vector<T, A>::iterator lo, typename std::vector<T, A>::iterator hi)
{
	int mid = 0;
	typedef typename std::vector<T, A>::iterator iterator;
	iterator j = lo;
	iterator p = hi - 1;
	for (iterator pos = lo; pos < p; ++pos) {
		if (*pos > *p)
			continue;
		else
		{
			std::swap(*j, *pos);
			j++;
			mid++;
		}
	}
	std::swap(*j, *p);
	return mid;
}

template <class T, class A>
void sortQuick(std::vector<T, A>& array, typename std::vector<T, A>::iterator lo, typename std::vector<T, A>::iterator hi)
{
	if (hi - lo <= 1) return;
	int mid = partition(array, lo, hi);
	sortQuick(array, lo, lo + mid);
	sortQuick(array, lo + mid + 1, hi);
}

template <class T, class A>
void quickSort(std::vector<T, A>& array)
{
	typename std::vector<T, A>::iterator begin = array.begin();
	typename std::vector<T, A>::iterator end = array.end();
	sortQuick(array, begin, end);
}



#endif /* SORTS_H_ */
