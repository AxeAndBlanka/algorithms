#include "SparseGraphWeight.h"

template <class T>
SparseGraphWeight<T>::SparseGraphWeight(int V, bool d) :
	mV(V), mE(0), mDirected(d), mAdj(mV)
{
}

template <class T>
void SparseGraphWeight<T>::addEdge(Edge<T>* e)
{
	mAdj[e->v1()] = new node(e, mAdj[e->v1()]);
	if (!mDirected)
		mAdj[e->v2()] = new node(e, mAdj[e->v2()]);
	mE++;
}

template <class T>
void SparseGraphWeight<T>::addEdge(int v1, int v2, T w)
{
	Edge<T>* e = new Edge<T>(v1, v2, w);
	addEdge(e);
	mE++;
}

template <class T>
void SparseGraphWeight<T>::print() const
{
	for (int i = 0; i < mV; ++i)
	{
		std::cout << i << ": ";
		typename SparseGraphWeight<T>::adjIterator A(*this, i);
		for (Edge<T>* pos = A.beg(); !A.end(); pos =A.nxt())
			std::cout << pos->v1() << "-" << pos->w() << "-" << pos->v2() << "; ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

/*int main()
{
	SparseGraphWeight<float> g(5);
	g.addEdge(2, 3, 1);
	g.addEdge(2, 4, 3);
	g.print();
	return 0;
}*/
