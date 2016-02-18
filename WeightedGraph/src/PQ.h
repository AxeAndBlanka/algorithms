#ifndef PQ_H_
#define PQ_H_

#include <vector>

template <class T>
class PQ
{
public:
	PQ(int N, const std::vector<T>& a, int d = 3) :
		d(d), N(0), pq(N+1, 0), qp(N + 1, 0), a(a)
	{
	}

	int empty() const { return N == 0; }
	void insert(int v)
	{
		pq[++N] = v;
		qp[v] = N;
		fixUp(N);
	}
	int getmin()
	{
		exch(1, N);
		fixDown(1, N - 1);
		return pq[N--];
	}
	void lower(int k)
	{
		fixUp(qp[k]);
	}
private:
	int d, N;
	std::vector<int> pq, qp;
	const std::vector<T>& a;
	void exch(int i, int j)
	{
		std::swap(pq[i], pq[j]);
		qp[pq[i]] = i; qp[pq[j]] = j;
	}
	void fixUp(int k)
	{
		while (k > 1 && a[pq[(k + d - 2) / d]] > a[pq[k]])
		{
			exch(k, (k + d - 2) / d);
			k = (k + d - 2) / d;
		}
	}
	void fixDown(int k, int N)
	{
		int j;
		while ((j = d * (k - 1) + 2) <= N)
		{
			for (int i = j + 1; i < j + d && i <= N; ++i)
				if (a[pq[j]] > a[pq[i]]) j = i;
			if (!(a[pq[k]] > a[pq[j]])) break;
			exch(k, j);
			k = j;
		}
	}
};

#endif /* PQ_H_ */
