#ifndef DENSEGRAPHWEIGHT_H_
#define DENSEGRAPHWEIGHT_H_

#include <vector>
#include "Edge.h"

template <class T>
class DenseGraphWeight
{
public:
	DenseGraphWeight(int V, bool d = false);
	int V() const { return mV; }
	int E() const {return mE; }
	bool directed() const { return mDirected; }
	void insert(Edge<T>* e);
	void remove(Edge<T>* e);
	Edge<T>* edge(int v1, int v2) const { return adj[v1][v2]; }
	class adjIterator;
	friend class adjIterator;
private:
	int mV, mE;
	bool mDirected;
	std::vector< std::vector< Edge<T>* > > adj;
};

template <class T>
class DenseGraphWeight<T>::adjIterator
{
public:
	adjIterator(const DenseGraphWeight<T>& g, int v) :
		g(g), v(v), i(0)
	{
	}
	Edge<T>* beg()
	{
		i = -1;
		return nxt();
	}
	Edge<T>* nxt()
	{
		for (int i = 0; i < g.V(); ++i)
			if (g.edge(v, i)) return g.adj[v][i];
		return 0;
	}
	bool end() const { return i >= g.V(); }
private:
	const DenseGraphWeight<T>& g;
	int i, v;
};



#endif /* DENSEGRAPHWEIGHT_H_ */
