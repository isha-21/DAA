// C++ program to find shortest path with exactly k edges
#include <bits/stdc++.h>
using namespace std;

#define V 4
#define INF INT_MAX

int shortest(int gr[][V], int u, int v, int k)
{
if (k == 0 && u == v)			 return 0;
if (k == 1 && gr[u][v] != INF) return gr[u][v];
if (k <= 0)					 return INF;

int out = INF;

for (int i = 0; i < V; i++)
{
	if (gr[u][i] != INF && u != i && v != i)
	{
		int rec_out = shortest(gr, i, v, k-1);
		if (rec_out != INF)
			out = min(out, gr[u][i] + rec_out);
	}
}
return out;
}

int main()
{
	int gr[V][V] = { {0, 10, 3, 2},
						{INF, 0, INF, 7},
						{INF, INF, 0, 6},
						{INF, INF, INF, 0}
					};
	int u = 0, v = 3, k = 1;
	cout << "Weight of the shortest path is " <<
		shortest(gr, u, v, k);
	return 0;
}
