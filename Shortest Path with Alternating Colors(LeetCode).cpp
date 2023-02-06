// Shortest Path with Alternating Colors(LeetCode).
#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;
vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
{
    // Red -> 1
    // Blue -> 2
    vector<int> dis(n , -1);
    vector<pair<int, int>> adj[n + 1];
    for (auto vec : redEdges)
    {
        adj[vec[0]].push_back({vec[1], 1});
    }
    for (auto vec : blueEdges)
    {
        adj[vec[0]].push_back({vec[1], 2});
    }
    queue<vector<int>> q;
    q.push({0, 0, -1});
    while (q.size() > 0)
    {
        auto currVec = q.front();
        q.pop();
        int currv = currVec[0], edgeColor = currVec[2];
        if (dis[currv] == inf)
        {
            dis[currv] = currVec[1];
        }
        for (auto &childPair : adj[currv])
        {
            int childV = childPair.first, edgeColorOfChild = childPair.second;
            // We have to take care of the fact that whether an edge has already been visited or not.
            if (childV != -1 && (edgeColor == -1 || edgeColor != edgeColorOfChild))
            {
                q.push({childV, currVec[1] + 1, edgeColorOfChild});
                childPair.first = -1;
            }
        }
    }
    return dis;
}
