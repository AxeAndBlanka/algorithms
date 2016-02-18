#include "SparseGraph.h"
#include <queue>

SparseGraph::SparseGraph(int V) :
	mV(V), mE(0), mAdj(V)
{
}

bool SparseGraph::addEdge(int v, int w)
{
	if (v < 0 || v >= mV || w < 0 || w >= mV)
		return false;
	mAdj[v].push_back(w);
	mAdj[w].push_back(v);
	mE++;
	return true;
}

bool SparseGraph::removeEdge(int v, int w)
{
	if (v < 0 || v >= mV || w < 0 || w >= mV)
		return false;
	mAdj[v].remove(w);
	mAdj[w].remove(v);
	mE--;
	return true;
}

std::ostream& operator<<(std::ostream& cout, SparseGraph& graph)
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

std::istream& operator>>(std::istream& cin, SparseGraph& graph)
{
	int v, w;
	while (cin)
	{
		cin >> v >> w;
		graph.addEdge(v, w);
	}
	return cin;
}

void SparseGraph::distanceBFS(int s, std::vector<int>& edgeTo) const
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
