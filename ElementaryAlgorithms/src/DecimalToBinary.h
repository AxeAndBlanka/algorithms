#ifndef DECIMALTOBINARY_H_
#define DECIMALTOBINARY_H_

#include <iostream>
#include <list>

void decimalToBinary()
{
	std::cout << "Enter decimal number:" << std::endl;
    int decimal;
    std::cin >> decimal;
	std::list<bool> answer;
	while (decimal != 0)
	{
		answer.push_front(bool(decimal % 2));
		decimal /= 2;
	}
	for (std::list<bool>::const_iterator pos = answer.begin(); pos != answer.end(); ++pos)
		std::cout << *pos;
	std::cout << std::endl;
}

#endif /* DECIMALTOBINARY_H_ */
