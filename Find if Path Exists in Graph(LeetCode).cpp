//Find if Path Exists in Graph(LeetCode).
#include <bits/stdc++.h>
using namespace std;
bool bfs(vector<vector<int>> &graph, int source, int n, int dest)
{
    queue<int> q;
    vector<int> vis(n + 1, 0);
    q.push(source);
    while (q.size() > 0)
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            int x = q.front();
            if (x == dest)
                return true;
            q.pop();
            vis[x] = 1;
            // cnt++;
            for (auto p : graph[x])
            {
                if (!vis[p])
                {
                    q.push(p);
                    vis[p] = 1;
                }
            }
        }
    }
    return false;
}
bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<int>> graph(n);
    for (auto edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    return bfs(graph, source, n, destination);
}
