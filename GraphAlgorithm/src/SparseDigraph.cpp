#include "SparseDigraph.h"
#include <queue>

SparseDigraph::SparseDigraph(int V) :
	mV(V), mE(0), mAdj(V)
{
}

bool SparseDigraph::addEdge(int v, int w)
{
	if (v < 0 || v >= mV || w < 0 || w >= mV)
		return false;
	mAdj[v].push_back(w);
	mE++;
	return true;
}

bool SparseDigraph::removeEdge(int v, int w)
{
	if (v < 0 || v >= mV || w < 0 || w >= mV)
		return false;
	mAdj[v].remove(w);
	return true;
}

std::ostream& operator<<(std::ostream& cout, SparseDigraph& graph)
{
	for (int i = 0; i < graph.mV; ++i)
	{
		cout << i << ": ";
		for (std::list<int>::const_iterator pos = graph.mAdj[i].begin(); pos != graph.mAdj[i].end(); ++pos)
			cout << *pos << " ";
		cout << std::endl;
	}
	cout << std::endl;
	return cout;
}

std::istream& operator>>(std::istream& cin, SparseDigraph& graph)
{
	int v, w;
	while (cin)
	{
		cin >> v >> w;
		graph.addEdge(v, w);
	}
	return cin;
}

void SparseDigraph::distanceBFS(int s, std::vector<int>& edgeTo) const
{
	std::vector<bool> marked(mV, false);
	edgeTo.assign(mV, -1);
	std::queue<int> q;
	q.push(s);
	edgeTo[s] = 0;
	marked[s] = true;
	while(!q.empty())
	{
        int v = q.front();
        q.pop();
        for (std::list<int>::const_iterator pos = mAdj[v].begin(); pos != mAdj[v].end(); ++pos)
        {
        	if (!marked[*pos])
        	{
        		q.push(*pos);
        		marked[*pos] = true;
        		edgeTo[*pos] = edgeTo[v] + 1;
        	}
        }
	}
}
