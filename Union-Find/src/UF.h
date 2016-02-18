//============================================================================
// Weighted Union-Find. Insert - lnN, Find - lnN
// Union-Find with Quick Find. Insert - N, Find - 1
// Union-Find with Space Limit.
//============================================================================

#ifndef UF_H_
#define UF_H_

#include <vector>

class WeightedUnionFind
{
public:
	WeightedUnionFind(int N) :
		N(N), id(N), sz(N), all(false)
	{
		for (int i = 0; i < N; ++i)
		{
			id[i] = i;
			sz[i] = 1;
		}
	}
	bool unione(int p, int q)
	{
		if (all) return false;
		while (p != id[p]) p = id[p];
		while (q != id[q]) q = id[q];
		if (p == q) return false;
		if (sz[p] < sz[q])
		{
			id[p] = q;
			sz[q] += sz[p];
			if (sz[q] == N) all = true;
			return true;
		}
		else
		{
			id[q] = p;
			sz[p] += sz[q];
			if (sz[p] == N) all = true;
			return true;
		}
	}
	bool connected(int p, int q)
	{
		if (all) return true;
		// int i = p, j = q; // Using connected often
		while (p != id[p]) p = id[p];
		while (q != id[q]) q = id[q];
		// id[i] = p; id[j] = q; // Using connected often
		return (p == q);
	}
private:
	int N;
	std::vector<int> id;
	std::vector<int> sz;
	bool all;
};

class QuickFind
{
public:
	QuickFind(int N) :
		N(N), id(N)
	{
		for (int i = 0; i < N; ++i)
			id[i] = i;
	}
	bool unione(int p, int q)
	{
		int t = id[p];
		if (t == id[q])
			return false;
		for (int i = 0; i < N; ++i)
		{
			if (id[i] == t) id[i] = id[q];
		}
		return true;
	}
	bool connected(int p, int q)
	{
		return (id[p] == id[q]);
	}
private:
	int N;
	std::vector<int> id;
};

class UnionFindWithoutSpace
{
public:
	UnionFindWithoutSpace(int N) :
		N(N), id(N)
	{
		for (int i = 0; i < N; ++i)
			id[i] = i;
	}
	bool unione(int p, int q)
	{
		while (p != id[p]) p = id[p];
		while (q != id[q]) q = id[q];
		if (p == q) return false;
		id[p] = q;
		return true;
	}
	bool connected(int p, int q)
	{
		int i = p; int j = q;
		while (p != id[p]) p = id[p];
		while (q != id[q]) q = id[q];
		id[i] = p;
		id[j] = q;
		return (p == q);
	}
private:
	int N;
	std::vector<int> id;
};

#endif /* UF_H_ */
