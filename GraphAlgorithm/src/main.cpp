#include <cassert>
#include "DenseGraph.h"
#include "DenseDigraph.h"
#include "SparseGraph.h"
#include "SparseDigraph.h"

using namespace std;

void test()
{
	DenseGraph t(5);
	assert(t.addEdge(2, 3));
	assert(!t.addEdge(3, 2));
	assert(t.addEdge(1, 3));
	assert(!t.removeEdge(4, 1));
	assert(t.removeEdge(2, 3));
	std::cout << t;
	DenseDigraph r(5);
	assert(r.addEdge(2, 3));
	assert(r.addEdge(3, 2));
	assert(!r.addEdge(2, 3));
	assert(r.addEdge(1, 2));
	assert(!r.removeEdge(4, 1));
	assert(r.removeEdge(2, 3));
	std::cout << r;
	SparseGraph s(5);
	assert(s.addEdge(2, 3));
	assert(s.addEdge(3, 2));
	assert(s.addEdge(1, 2));
	//assert(s.removeEdge(2, 3));
	std::cout << s;
}

int main()
{
	test();
	return 0;
}
