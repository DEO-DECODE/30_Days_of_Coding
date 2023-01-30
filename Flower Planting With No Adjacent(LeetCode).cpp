// Flower Planting With No Adjacent(LeetCode)
#include <bits/stdc++.h>
using namespace std;
set<vector<int>> collec;
bool isPossible(int node, int col, vector<int> adj[], vector<int> &color, int N)
{
    for (auto adj_node : adj[node])
    {
        if (color[adj_node] == col)
            return false;
    }
    return true;
}
bool dfs(int vertex, vector<int> adj[], vector<int> &color, int N)
{
    if (vertex == N)
    {
        collec.insert(color);
        return true;
    }
    for (int col = 1; col <= 4; ++col)
    {
        if (isPossible(vertex, col, adj, color, N))
        {
            color[vertex] = col;
            if(dfs(vertex + 1, adj, color, N)) return true;
            color[vertex] = 0;
        }
    }
    return false;
}
vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
{
    vector<int> ans(n), vis(n, 0), color(n, 0);
    vector<int> adj[n];
    for (int i = 0; i < paths.size(); i++)
    {
        adj[paths[i][0]-1].push_back(paths[i][1]-1);
        adj[paths[i][1]-1].push_back(paths[i][0]-1);
    }
    dfs(0, adj, color, n);
    auto possAns = (*collec.begin());
    // possAns.erase(possAns.begin());
    return possAns;
}
int main(){
    int n = 4;
    vector<vector<int>> paths = {{1,2},{2,3},{3,4},{4,1},{1,3},{2,4}};
    auto ans=gardenNoAdj(n,paths);
}
