//Is Graph Bipartite(LeetCode)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const int N = 101;

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
    bool isBipartite(vector<vector<int>> &graph)
    {
        bool flag = false;
        vector<int> vis(N, 0);
        int col = 1;
        for (int i = 0; i < graph.size(); ++i)
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
};
