#ifndef DECIMALTOBINARY_H_
#define DECIMALTOBINARY_H_

#include <iostream>
#include <vector>
#include <algorithm>

void decimalToBinary(long long decimal, std::vector<bool>& answer)
{
	while (decimal != 0)
	{
		answer.push_back(bool(decimal % 2));
		decimal /= 2;
	}
	std::reverse(answer.begin(), answer.end()); 
}

long long binaryToDecimal(const vector<bool>& binary)
{
    long long answer = 0;
    int i = 0;
    for (auto pos = binary.rbegin(); pos != binary.rend(); ++pos, ++i)
    {
        if (*pos)
            answer += pow(2, i);
    }
   return answer;    
}

#endif /* DECIMALTOBINARY_H_ */
