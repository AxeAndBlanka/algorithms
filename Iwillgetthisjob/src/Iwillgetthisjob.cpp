#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template <class T>
int find(const vector<T>& array, T elem)
{
    int possition = -1;
    unsigned size = array.size();
    unsigned leftOfRange = 0;
    unsigned rightOfRange = size - 1;
    unsigned middleOfRange = size / 2;
    while (leftOfRange < rightOfRange)
    {
        unsigned middleOfRange = (rightOfRange - leftOfRange) / 2 + leftOfRange;
        if (array[middleOfRange] == elem)
            return middleOfRange;
        if (array[leftOfRange] == elem)
            return leftOfRange;
        if (array[rightOfRange] == elem)
            return rightOfRange;
        if (elem < array[middleOfRange])
        {
            if ((array[leftOfRange] <= array[middleOfRange] && elem >= array[leftOfRange])||
                    (array[leftOfRange] >= array[middleOfRange] && elem < array[middleOfRange]))
                rightOfRange = middleOfRange - 1;
            else
                leftOfRange = middleOfRange + 1;
        }
        if (elem > array[middleOfRange])
        {
            if ((array[rightOfRange] >= array[middleOfRange] && elem <= array[rightOfRange])||
                    (array[rightOfRange] <= array[middleOfRange] && elem > array[middleOfRange]))
                leftOfRange = middleOfRange + 1;
            else
                rightOfRange = middleOfRange - 1;
        }
    }
    return possition;
}

void test()
{
    vector<int> array = {6, 7, 8, 9, 1, 2, 3, 4, 5};
    assert(0 == find(array, 6));
    assert(-1 == find(array, 15));
    assert(8 == find(array, 5));
    assert(1 == find(array, 7));
    cout << "Tests passed!";
}

int main()
{
    test();
    return 0;
}
