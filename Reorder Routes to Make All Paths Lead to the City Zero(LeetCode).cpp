//Reorder Routes to Make All Paths Lead to the City Zero(LeetCode).
#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void dfs(int vertex, vector<vector<int>> &graph, vector<int> &vis)
{
    vis[abs(vertex)] = 1;
    for (auto child : graph[abs(vertex)])
    {
        if (vis[abs(child)])
            continue;
        if (child > 0)
            cnt++;
        dfs(child, graph, vis);
    }
}
int minReorder(int n, vector<vector<int>> &connections)
{
    cnt = 0;
    vector<vector<int>> graph(n);
    vector<int> vis(n, 0);
    for (auto vec : connections)
    {
        // directed graph
        graph[vec[0]].push_back(vec[1]);
        graph[vec[1]].push_back(-vec[0]);
    }
    dfs(0, graph, vis);
    return cnt;
}
