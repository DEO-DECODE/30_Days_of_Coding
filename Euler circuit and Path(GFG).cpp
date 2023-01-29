// Euler circuit and Path(GFG)
#include <bits/stdc++.h>
using namespace std;
int isEularCircuit(int V, vector<int> adj[])
{
	// Code here
	int count = 0;
	for (int i = 0; i < V; i++)
	{
		int nbrs = adj[i].size();
		if (nbrs % 2 != 0)
		{
			// odd degree off vertices
			count++;
		}
	}
	// for eular circuit, all are odd degree
	if (count == 0)
	{
		return 2;
	}
	// for eular path, there will be a 0 or 2 odd degree
	else if (count == 0 || count == 2)
	{
		return 1;
	}
	return 0;
}
