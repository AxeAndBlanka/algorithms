#ifndef ISPRIME_H_
#define ISPRIME_H_

#include <iostream>

bool isPrime(int n)
{
    if (n == 1)
        return false;
    else if (n <= 3)
        return true;
    else if ((n % 2 == 0) || (n % 3 == 0))
        return false;
    int i = 5;
    while (i*i <= n)
    {
        if ((n % i == 0) || (n % (i + 2) == 0))
            return false;
        i += 6;
    }
    return true;
}

void testIsPrime()
{
	std::cout << "Enter number: " << std::endl;
    int n;
    std::cin >> n;
    if (isPrime(n))
    	std::cout << "Prime" << std::endl;
    else
    	std::cout << "Not prime" << std::endl;
}

#endif /* ISPRIME_H_ */
