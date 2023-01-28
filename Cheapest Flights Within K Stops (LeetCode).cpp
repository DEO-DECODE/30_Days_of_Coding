// Cheapest Flights Within K Stops (LeetCode)
#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    for (auto vec : flights)
    {
        adj[vec[0]].push_back({vec[1], vec[2]});
    }
    set<pair<int, pair<int, int>>> st;
    st.insert({0, {src, 0}});
    // vector<int> vis(n, 0), costToReachVertex(n, inf);
    while (st.size() > 0)
    {
        auto node = (*st.begin());
        int currv = node.second.first;
        int stops = node.second.second;
        int cost = node.first;
        st.erase(st.begin());
        if (currv == dst)
            return cost;
        if (stops > k)
            continue;
        // if (vis[currv])
        //     continue;
        // vis[currv] = 1;
        for (auto childpr : adj[currv])
        {
            int childV = childpr.first;
            int costFromCurrvToChildV = childpr.second;
            st.insert({cost+costFromCurrvToChildV,{childV, stops+1}});
        }
    }
    return -1;
}
