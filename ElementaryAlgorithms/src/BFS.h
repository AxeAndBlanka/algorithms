#ifndef BFS_H_
#define BFS_H_

#include <vector>
#include <list>
#include <queue>
#include <iostream>

typedef std::vector< std::list <int> > graphSparse;

void visitAllVertexes(const graphSparse& graph, int s)
{
	int N = graph.size();
	std::vector<bool> marked(N, false);
	std::vector<int> edgeTo(N, -1);
	std::queue<int> q;
	q.push(s);
	edgeTo[s] = s;
	marked[s] = true;
	while(!q.empty())
	{
        int v = q.front();
        q.pop();
        for (std::list<int>::const_iterator pos = graph[v].begin(); pos != graph[v].end(); ++pos)
        {
        	if (!marked[*pos])
        	{
        		q.push(*pos);
        		marked[*pos] = true;
        		edgeTo[*pos] = v;
        	}
        }
	}
}

int findShortestDistance(const graphSparse& graph, int startV, int finishV)
{
	int N = graph.size();
	std::vector<bool> marked(N, false);
	std::vector<int> edgeTo(N, -1);
	std::queue<int> q;
	q.push(startV);
	edgeTo[startV] = 0;
	marked[startV] = true;
	while(!q.empty())
	{
        int v = q.front();
        q.pop();
        for (std::list<int>::const_iterator pos = graph[v].begin(); pos != graph[v].end(); ++pos)
        {
        	if (*pos == finishV)
        		return edgeTo[v] + 1;
        	if (!marked[*pos])
        	{
        		q.push(*pos);
        		marked[*pos] = true;
        		edgeTo[*pos] = edgeTo[v] + 1;
        	}
        }
	}
	return -1;
}

void testBFS()
{
	const int S = 7;
	graphSparse g(S);
	g[0].push_back(1);
	g[0].push_back(2);
	g[1].push_back(3);
	g[1].push_back(6);
	g[2].push_back(0);
	g[2].push_back(3);
	g[2].push_back(4);
	g[3].push_back(1);
	g[3].push_back(2);
	g[3].push_back(4);
	g[3].push_back(5);
	g[4].push_back(2);
	g[4].push_back(3);
	g[4].push_back(5);
	g[5].push_back(3);
	g[5].push_back(4);
	g[6].push_back(1);
	visitAllVertexes(g, 0);
	if (1 != findShortestDistance(g, 0, 1) ||
		2 != findShortestDistance(g, 0, 3) ||
		3 != findShortestDistance(g, 0, 5))
		std::cout << " Error!" << std::endl;
}

#endif
