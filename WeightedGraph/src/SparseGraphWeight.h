#ifndef SPARSEGRAPHWEIGHT_H_
#define SPARSEGRAPHWEIGHT_H_

#include <vector>
#include <iostream>

#include "Edge.h"

template <class T>
class SparseGraphWeight
{
public:
	SparseGraphWeight(int V, bool d = false);
	int V() const { return mV; }
	int E() const { return mE; }
	void addEdge(Edge<T>* e);
	void addEdge(int v1, int v2, T w);
	void print() const;
	class adjIterator;
	friend class adjIterator;
private:
	int mV, mE;
	bool mDirected;
	struct node
	{
		Edge<T>* e;
		node* next;
		node(Edge<T>* e, node* next) : e(e), next(next) {}
	};
	typedef node* link;
	std::vector<link> mAdj;
};

template <class T>
class SparseGraphWeight<T>::adjIterator
{
public:
	adjIterator(const SparseGraphWeight<T>& g, int v) :
		mG(g), mV(v)
	{
		i = 0;
	}
	Edge<T>* beg()
	{
		i = mG.mAdj[mV];
		return i ? i->e : 0;
	}
	Edge<T>* nxt()
	{
		if (i) i = i->next;
		return i ? i->e : 0;
	}
	bool end()
	{
		return i == 0;
	}
private:
	const SparseGraphWeight<T>& mG;
	int mV;
	SparseGraphWeight::link i;
};

#endif /* SPARSEGRAPHWEIGHT_H_ */
