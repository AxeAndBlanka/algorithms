#include "DenseGraph.h"
#include <queue>

DenseGraph::DenseGraph(int V) :
	mV(V), mE(0), mAdj(V)
{
	for (int i = 0; i < mV; ++i)
		mAdj[i].assign(mV, false);
}

bool DenseGraph::addEdge(int v, int w)
{
	if (v < 0 || v >= mV || w < 0 || w >= mV)
		return false;
	if (mAdj[v][w] == false)
	{
		mE++;
		mAdj[v][w] = true;
		mAdj[w][v] = true;
		return true;
	}
	else
		return false;
}

bool DenseGraph::removeEdge(int v, int w)
{
	if (v < 0 || v >= mV || w < 0 || w >= mV)
		return false;
	if (mAdj[v][w] == true)
	{
		mE--;
		mAdj[v][w] = false;
		mAdj[w][v] = false;
		return true;
	}
	else
		return false;
}

bool DenseGraph::edge(int v, int w) const
{
	return mAdj[v][w];
}

std::ostream& operator<<(std::ostream& cout, DenseGraph& graph)
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

std::istream& operator>>(std::istream& cin, DenseGraph& graph)
{
	int v, w;
	while (cin)
	{
		cin >> v >> w;
		graph.addEdge(v, w);
	}
	return cin;
}

void DenseGraph::distanceBFS(const int s, std::vector<int>& edgeTo) const
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

void DenseGraph::pathBFS(const int s, std::vector<int>& edgeTo) const
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
        		edgeTo[i] = v;
        	}
        }
	}
}

int DenseGraph::distanceBFS(const int v1, const int v2) const
{
	int result = 0;
	std::vector<bool> marked(mV, false);
	std::vector<int> edgeTo(mV, -1);
	std::queue<int> q;
	q.push(v1);
	edgeTo[v1] = 0;
	marked[v1] = true;
	int v = v1;
	while(!q.empty() && v != v2)
	{
        v = q.front();
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
	result = edgeTo[v2];
	return result;
}

void DenseGraph::pathBFS(const int v1, const int v2, std::vector<int>& edgeTo) const
{
	std::vector<bool> marked(mV, false);
	edgeTo.assign(mV, -1);
	std::queue<int> q;
	q.push(v1);
	edgeTo[v1] = 0;
	marked[v1] = true;
	int v = v1;
	while(!q.empty() && v != v2)
	{
        v = q.front();
        q.pop();
        for (int i = 0; i < mV; ++i)
        {
        	if (edge(v, i) && !marked[i])
        	{
        		q.push(i);
        		marked[i] = true;
        		edgeTo[i] = v;
        	}
        }
	}
}
