#ifndef DENSEGRAPH_H_
#define DENSEGRAPH_H_

#include <vector>
#include <iostream>

class DenseGraph
{
public:
	DenseGraph(int V);
	inline int V() const { return mV; }
	inline int E() const { return mE; }
	bool addEdge(int v, int w);
	bool removeEdge(int v, int w);
	bool edge(int v, int w) const;
	friend std::ostream& operator<<(std::ostream& cout, DenseGraph& graph);
	friend std::istream& operator>>(std::istream& cin, DenseGraph& graph);

	// edgeTo describe distances between vertex s and all others
	// edgeTo[i] return -1, if vertices s and i not connected
	void distanceBFS(const int s, std::vector<int>& edgeTo) const;

	// edgeTo describe path between vertex s and all others
	// edgeTo[i] return -1, if vertices s and i not connected
	void pathBFS(const int s, std::vector<int>& edgeTo) const;

	// distance between two vertices v1 and v2
	// return -1, if v1 and v2 not connected
	int distanceBFS(const int v1, const int v2) const;

	// edgeTo describe path between vertex v1 and v2
	// edgeTo[i] return -1, if vertices v1 and v2 not connected
	void pathBFS(const int v1, const int v2, std::vector<int>& edgeTo) const;

private:
	int mV, mE;
	std::vector< std::vector<bool> > mAdj;
};

#endif /* DENSEGRAPH_H_ */

