// Shortest-paths tree, Dijkstra's algorithm

#include "PQ.h"
#include "SparseGraphWeight.cpp"
#include <climits>

template <class T>
class SPT
{
public:
	SPT(const SparseGraphWeight<T>& g, int s) :
		g(g), wt(g.V(), INT_MAX), spt(g.V())
	{
		PQ<T> pQ(g.V(), wt);
		for (int v = 0; v < g.V(); ++v)
			pQ.insert(v);
		wt[s] = 0.0;
		pQ.lower(s);
		while (!pQ.empty())
		{
			int v = pQ.getmin();
			if (v != s && spt[v] == 0)
				return;
			typename SparseGraphWeight<T>::adjIterator A(g, v);
			for (Edge<T>* e = A.beg(); !A.end(); e = A.nxt())
			{
				int w = e->other(v);
				T P = wt[v] + e->w();
				if (P < wt[w])
				{
					wt[w] = P;
					pQ.lower(w);
					spt[w] = e;
				}
			}
		}
	}
	Edge<T>* pathR(int v) const { return spt[v]; }
	T dist(int v) const { return wt[v]; }
private:
	const SparseGraphWeight<T>& g;
	std::vector<T> wt;
	std::vector< Edge<T>* > spt;
};

int main()
{
	SparseGraphWeight<int> gg(5);
	gg.addEdge(0, 1, 60);
	gg.addEdge(2, 4, 70);
	gg.addEdge(0, 3, 120);
	gg.addEdge(4, 3, 150);
	gg.addEdge(1, 2, 80);
	gg.print();
	SPT<int> spt(gg, 0);
	std::cout << "Dist: " << spt.dist(4) << " " << spt.dist(3);
	return 0;
}
