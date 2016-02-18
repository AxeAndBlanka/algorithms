#include "DenseGraphWeight.h"

template <class T>
DenseGraphWeight<T>::DenseGraphWeight(int V, bool d) :
	mV(V), mE(0), mDirected(d), adj(V)
{
	for (int i = 0; i < V; ++i)
	{
		adj[i].reserve(V);
		for (int j = 0; j < V; ++j)
			adj[i][j] = 0;
	}
}

template <class T>
void DenseGraphWeight<T>::insert(Edge<T>* e)
{
	int v1 = e->v1();
	int v2 = e->v2();
	if (adj[v1][v2] == 0)
		mE++;
	adj[v1][v2] = e;
	if (!mDirected)
		adj[v2][v1] = e;
}

template <class T>
void DenseGraphWeight<T>::remove(Edge<T>* e)
{
	int v1 = e->v1();
	int v2 = e->v2();
	if (adj[v1][v2] != 0)
		mE--;
	adj[v1][v2] = 0;
	if (!mDirected)
		adj[v2][v1] = 0;
}
