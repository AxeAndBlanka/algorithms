#ifndef EDGE_H_
#define EDGE_H_

#include <iostream>

template <class T>
class Edge
{
public:
	Edge(int v1, int v2, T w) : mV1(v1), mV2(v2), mW(w){ };
	int v1() const { return mV1; };
	int v2() const { return mV2; };
	T w() const { return mW; };
	bool from(int v) const { return v == mV1; };
	int other(int v) const { return from(v) ? mV2 : mV1; };
	void show() const { std::cout << mV1 << "-" << mW << "-" << mV2 << "; "; };
private:
	int mV1, mV2;
	T mW;
};

#endif /* EDGE_H_ */
