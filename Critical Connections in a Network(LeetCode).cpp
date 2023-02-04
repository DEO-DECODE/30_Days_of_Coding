// Critical Connections in a Network(LeetCode)
#include <bits/stdc++.h>
using namespace std;
void dfs(int vertex, int parent, vector<int> adj[], vector<int> &low, vector<int> &in, vector<int> &vis, int &timer, vector<vector<int>> &ans)
{
    in[vertex] = low[vertex] = timer++;
    vis[vertex] = 1;
    for (auto child : adj[vertex])
    {
        if (child == parent)
            continue;
        if (vis[child])
        {
            low[vertex] = min(low[vertex], in[child]);
        }
        else
        {
            dfs(child, vertex, adj, low, in, vis, timer, ans);
            if (low[child] > in[vertex])
            {
                ans.push_back({vertex, child});
            }
            low[vertex] = min(low[vertex], low[child]);
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<int> adj[n + 1], in(n + 1, 0), low(n + 1, 0), vis(n + 1, 0);
    vector<vector<int>> ans;
    int timer = 0;
    for (auto edge : connections)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            dfs(i, -1, adj, low, in, vis, timer, ans);
        }
    }
    return ans;
}
