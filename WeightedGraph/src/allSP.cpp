// All-pairs shortest paths, Dijkstra's algorithm

/*#include <vector>
#include "SPT.cpp"
#include "DenseGraphWeight.cpp"

template <class T>
class allSP
{
public:
	allSP(const SparseGraphWeight<T>& g) :
		g(g), a(g.V())
	{
		for (int i = 0; i < g.V(); ++i)
			a[i] = new SPT<T>(g, i);
	}
	Edge<T>* pathR(int s, int t) const { return a[s]->pathR(); }
	double dist(int s, int t) const { return a[s]->dist(t); }
private:
	const SparseGraphWeight<T>& g;
	std::vector< SPT<T>* > a;
};

//Floyd's algorithm
template <class T>
class allSPDense
{
public:
	allSPDense(const DenseGraphWeight<T>& g) :
		g(g), p(g.V()), d(g.V())
	{
		int V = g.V();
		for (int i = 0; i < V; ++i)
		{
			p[i].reserve(V);
			for (int j = 0; j < V; ++j)
				p[i][j] = 0;
			d[i].assign(V, V);
		}
		for (int s = 0; s < V; ++s)
			for (int t = 0; t < V; ++t)
			{
				if (g.edge(s, t))
				{
					p[s][t] = g.edge(s, t);
					d[s][t] = g.edge(s, t)->w();
				}
				for (int s = 0; s < V; ++s)
					d[s][s] = 0;
				for (int i = 0; i < V; ++i)
					for (int s = 0; s < V; ++s)
						if (p[s][i])
							for (int t = 0; t < V; ++t)
								if (s != t)
									if (d[s][t] > d[s][i] + d[i][t])
									{
										p[s][t] = p[s][i];
										d[s][t] = d[s][i] + d[i][t];
									}
			}
	}
	Edge<T>* path(int s, int t) const { return p[s][t]; }
	double dist(int s, int t) const { return d[s][t]; }
private:
	const DenseGraphWeight<T>& g;
	std::vector< std::vector< Edge<T>* > > p;
	std::vector< std::vector<double> > d;
};

#include <iostream>

int main()
{
	int N, M;
	std::cin >> N >> M;
	int x, y, r;
	SparseGraphWeight<int> gS(N, true);
	for (int i = 0; i < M; ++i)
	{
		std::cin >> x >> y >> r;
		Edge<int>* eS = new Edge<int>(x - 1, y - 1, r);
		gS.addEdge(eS);
	}
	allSP<int> resS(gS);
	int Q;
	std::cin >> Q;
	int a, b;
	for (int i = 0; i < Q; ++i)
	{
		std::cin >> a >> b;
		int r = resS.dist(a - 1, b - 1);
		std::cout << r << std::endl;
	}
}*/

