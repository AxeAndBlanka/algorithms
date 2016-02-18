//Prim's MST algorithm

#include <vector>
#include "PQ.h"
#include "SparseGraphWeight.cpp"

template <class T>
class MST
{
public:
	MST(SparseGraphWeight<T>& g) :
		g(g), wt(g.V(), -1), fr(g.V()), mst(g.V())
	{
		for (int v = 0; v < g.V(); ++v)
			if (mst[v] == 0)
				pfs(v);
	}
	void show() const
	{
		for (int v = 1; v < mst.size(); ++v)
			if (mst[v]) mst[v]->show();
	}
private:
	const SparseGraphWeight<T>& g;
	std::vector<T> wt;
	std::vector< Edge<T>* > fr, mst;
	void pfs(int s)
	{
		PQ<T> pQ(g.V(), wt);
		pQ.insert(s);
		while (!pQ.empty())
		{
			int v = pQ.getmin();
			mst[v] = fr[v];
			typename SparseGraphWeight<T>::adjIterator A(g, v);
			for (Edge<T>* e = A.beg(); !A.end(); e = A.nxt())
			{
				T P = e->w();
				int w = e->other(v);
				if (fr[w] == 0)
				{
					wt[w] = P;
					pQ.insert(w);
					fr[w] = e;
 				}
				else if (mst[w] == 0 && P < wt[w])
				{
					wt[w] = P;
					pQ.lower(w);
					fr[w] = e;
				}
			}
		}
	}
};

/*int main()
{
	SparseGraphWeight<int> g(8);
	g.addEdge(0, 2, 4);
	g.addEdge(0, 5, 3);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 2);
	g.addEdge(0, 6, 6);
	g.addEdge(1, 7, 1);
	g.addEdge(3, 4, 2);
	g.addEdge(3, 5, 6);
	g.addEdge(4, 7, 1);
	g.addEdge(4, 6, 5);
	g.addEdge(6, 7, 2);
	g.print();
	MST<int> mst(g);
	mst.show();
	return 0;
}*/
