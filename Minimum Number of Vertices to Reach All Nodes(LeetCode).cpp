//Minimum Number of Vertices to Reach All Nodes(LeetCode).
#include <bits/stdc++.h>
using namespace std;
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    vector<int> indeg(n, 0), vis(n, 0);
    for (auto i : edges)
    {
        indeg[i[1]]++;
        vis[i[0]] = 1;
        vis[i[1]] = 1;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] || !indeg[i])
            ans.push_back(i);
    }
    return ans;
}
