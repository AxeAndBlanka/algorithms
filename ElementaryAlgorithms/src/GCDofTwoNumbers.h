#ifndef GCDOFTWONUMBERS_H_
#define GCDOFTWONUMBERS_H_

#include <iostream>

int findGCD(int a,int b)
{
    if (a == b)
        return a;
    if (a < b)
        std::swap(a, b);
    return findGCD(b, a - b);
}

void testFindGCD()
{
    int a, b;
    std::cout << "Enter first number: " << std::endl;
    std::cin >> a;
    std::cout << "Enter second number: " << std::endl;
    std::cin >> b;
    int gcd = findGCD(a,b);
    std::cout << gcd;
}

#endif /* GCDOFTWONUMBERS_H_ */
