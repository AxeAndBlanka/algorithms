//============================================================================
// Weighted Union-Find. Insert - , Find -
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "UF.h"

using namespace std;

void test()
{
	ifstream myfile("tests\\test2.txt");
	ofstream answer ("tests\\answer2.txt");
	if (myfile.is_open() && answer.is_open())
	{
		int N;
		myfile >> N;
		answer << N << endl;
		UnionFindWithoutSpace cc(N);
		char c;
		int p, q;
		while (myfile >> c >> p >> q)
		{
			bool isConnected = false;
			bool isUnion = false;
			if (c == 'U')
				isUnion = cc.unione(p, q);
			else
				isConnected = cc.connected(p, q);
			answer << c << ": (" << p << ", " << q << "): union - " << isUnion << ", connected - " << isConnected << endl;
		}
		answer.close();
		myfile.close();
	}
}

void randomTest()
{
	ofstream answer ("tests\\randomAnswer.txt");
	if (!answer.is_open()) return;
	int N = 100000;
	int M = 100000;
	UnionFindWithoutSpace cc(N);
	int p, q;
	for (int i = 0; i < M; ++i)
	{
		bool isConnected = false;
		bool isUnion = false;
		p = rand() % N;
		q = rand() % N;
		isUnion = cc.unione(p, q);
		p = rand() % N;
		q = rand() % N;
		isConnected = cc.connected(p, q);
		answer << "(" << p << ", " << q << "): union - " << isUnion << ", connected - " << isConnected << endl;
	}
	answer.close();
}

int main()
{
	randomTest();
	test();
	return 0;
}
