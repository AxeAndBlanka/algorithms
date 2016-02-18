#ifndef DENSEDIGRAPH_H_
#define DENSEDIGRAPH_H_

#include <vector>
#include <iostream>

class DenseDigraph
{
public:
	DenseDigraph(int V);
	inline int V() const { return mV; }
	inline int E() const { return mE; }
	bool addEdge(int v, int w);
	bool removeEdge(int v, int w);
	inline bool edge(int v, int w) const { return mAdj[v][w]; }
	friend std::ostream& operator<<(std::ostream& cout, DenseDigraph& graph);
	friend std::istream& operator>>(std::istream& cin, DenseDigraph& graph);
	void distanceBFS(int s, std::vector<int>& edgeTo) const;

private:
	int mV, mE;
	std::vector< std::vector<bool> > mAdj;
};

#endif /* DENSEDIGRAPH_H_ */
