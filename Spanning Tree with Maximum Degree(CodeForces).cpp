// Spanning Tree with Maximum Degree(CodeForces)
#include <bits/stdc++.h>
using namespace std;
/*
In Context Of Spanning Tree:
.If an edge makes the cycle , then we will not add that edge.
.Cycle tab hi create hogi Jab hm kisi naye node ko kisi visited node se connect kare.
*/
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> adj[n + 1], indeg(n + 1, 0);
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		indeg[x]++, indeg[y]++;
	}
	int node, maxm = 0;
	vector<int> vis(n + 1, 0);
	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (indeg[i] > maxm)
		{
			maxm = indeg[i];
			node = i;
		}
	}
	vis[node]=1;
	for(auto child: adj[node]){
		cout<<node<<" "<<child<<endl;
		vis[child]=1;
		q.push(child);
	}
	while (q.size()>0)
	{
		int currv=q.front();
		q.pop();
		for(auto child: adj[currv]){
			if(vis[child]) continue;
			cout<<currv<<" "<<child<<endl;
			vis[child]=1;
			q.push(child);
		}
	}
	
}
