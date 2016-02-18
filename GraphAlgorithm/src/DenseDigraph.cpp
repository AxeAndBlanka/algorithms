#include "DenseDigraph.h"
#include <queue>

DenseDigraph::DenseDigraph(int V) :
	mV(V), mE(0), mAdj(V)
{
	for (int i = 0; i < mV; ++i)
	{
		mAdj[i].assign(mV, false);
	}
}

bool DenseDigraph::addEdge(int v, int w)
{
	if (v < 0 || v >= mV || w < 0 || w >= mV)
		return false;
	if (mAdj[v][w] == false)
	{
		mE++;
		mAdj[v][w] = true;
		return true;
	}
	else
		return false;
}

bool DenseDigraph::removeEdge(int v, int w)
{
	if (v < 0 || v >= mV || w < 0 || w >= mV)
		return false;
	if (mAdj[v][w] == true)
	{
		mE--;
		mAdj[v][w] = false;
		return true;
	}
	else
		return false;
}

std::ostream& operator<<(std::ostream& cout, DenseDigraph& graph)
{
	for (int i = 0; i < graph.mV; ++i)
	{
		cout << i << ": ";
		for (int j = 0; j < graph.mV; ++j)
		{
			if (graph.mAdj[i][j] == true)
				cout << j << " ";
		}
		cout << std::endl;
	}
	cout << std::endl;
	return cout;
}

std::istream& operator>>(std::istream& cin, DenseDigraph& graph)
{
	int v, w;
	while (cin)
	{
		cin >> v >> w;
		graph.addEdge(v, w);
	}
	return cin;
}

void DenseDigraph::distanceBFS(int s, std::vector<int>& edgeTo) const
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
        for (int i = 0; i < mV; ++i)
        {
        	if (edge(v, i) && !marked[i])
        	{
        		q.push(i);
        		marked[i] = true;
        		edgeTo[i] = edgeTo[v] + 1;
        	}
        }
	}
}
