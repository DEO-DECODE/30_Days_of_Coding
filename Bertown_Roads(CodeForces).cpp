// Bertown Roads (CODEFORCES)
#include <bits/stdc++.h>
using namespace std;
/*
.Since Government has decided to make the traffic one directional on all roads. If we still want that we can visit to any node from any other node , then we should check wheter there is any bridge or not, that is graph should not have any bridge.
.For a node to have path to the root there should be a backedge in it's dfs subtree, so that it can reach a level up. A backeEdge means there is a node in the dfs subtree of node X, who is connected to some ancestor
of x.
If a Node is descendent then it should have higher in time w.r.t to the other node
Bridge:- The edge on whose removal, Graph is broken down into more number of components.
low[]:- It represents the lowest time of insertion among all the adjacent nodes.
*/
const int N = 1e5;
vector<int> adj[N + 1];
int in[N + 1], low[N + 1], vis[N + 1], timer;
bool hasbridge;
vector<pair<int, int>> edgelist;
void dfs(int node, int parent)
{
	vis[node] = 1;
	in[node] = low[node] = timer++;
	for (auto child : adj[node])
	{
		if (child == parent)
			continue;
		if (vis[child] == 1)
		{
			low[node] = min(low[node], in[child]);
			if (in[child] < in[node])
			{
				edgelist.push_back({node, child});
			}
		}
		else
		{
			dfs(child, node);
			low[node] = min(low[node], low[child]);
			if (low[child] > in[node])
			{
				hasbridge = true;
				return;
			}
			edgelist.push_back({node, child});
		}
	}
}

int main()
{
	int n, m, a, b;
	cin >> n >> m;
	while (m--)
		cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);
	dfs(3, -1);
	if (hasbridge)
		cout << 0;
	else
	{
		for (auto pr : edgelist)
			cout << pr.first << " -> " << pr.second << endl;
	}
}
