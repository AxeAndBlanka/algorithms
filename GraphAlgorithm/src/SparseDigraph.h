#ifndef SPARSEDIGRAPH_H_
#define SPARSEDIGRAPH_H_

#include <vector>
#include <list>
#include <iostream>

class SparseDigraph
{
public:
	SparseDigraph(int V);
	inline int V() const { return mV; }
	inline int E() const { return mE; }
	bool addEdge(int v, int w);
	bool removeEdge(int v, int w);
	const std::list<int>& adj(int v) const { return mAdj[v]; };
	friend std::ostream& operator<<(std::ostream& cout, SparseDigraph& graph);
	friend std::istream& operator>>(std::istream& cin, SparseDigraph& graph);
	void distanceBFS(int s, std::vector<int>& edgeTo) const;
private:
	int mV, mE;
	std::vector< std::list<int> > mAdj;
};

#endif /* SPARSEDIGRAPH_H_ */
