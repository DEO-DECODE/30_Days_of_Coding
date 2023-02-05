// Is Graph Bipartite?(LeetCode).
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &adj, int vertex, int par, vector<int> &vis, int col, bool &flag)
{
    vis[vertex] = col;
    for (auto child : adj[vertex])
    {
        if (vis[child] == 0)
        {
            dfs(adj, child, vertex, vis, 3 - col, flag);
        }
        else
        {
            if (child != par && vis[vertex] == vis[child])
            {
                flag = true;
                return;
            }
        }
    }
}
bool isBipartite(vector<vector<int>> &graph, int n)
{
    bool flag = false;
    vector<int> vis(n + 1, 0);
    int col = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            dfs(graph, i, -1, vis, col, flag);
        }
    }
    if (flag)
    {
        return false;
    }
    return true;
}
bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
    vector<vector<int>> graph(n+1);
    for (auto vec : dislikes)
    {
        graph[vec[0]].push_back(vec[1]);
        graph[vec[1]].push_back(vec[0]);
    }
    return isBipartite(graph, n);
}
