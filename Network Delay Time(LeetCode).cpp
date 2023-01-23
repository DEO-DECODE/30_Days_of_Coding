// Network Delay Time(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<pair<int, int>> adj[n + 1];
    vector<int> vis(n + 1, 0);
    vector<int> dis(n + 1, 1e9);
    set<pair<int, int>> st;
    st.insert({0, k});
    dis[k] = 0;
    for (int i = 0; i < times.size(); ++i)
    {
        adj[times[i][0]].push_back({times[i][1], times[i][2]});
    }
    int numnodes = 0;
    int ans = 0;
    while (st.size() > 0)
    {
        numnodes++;
        auto node = (*st.begin());
        st.erase(st.begin());
        int currv = node.second;
        if (vis[currv])
            continue;
        vis[currv] = 1;
        for (auto child : adj[currv])
        {
            int childV = child.first;
            int wt = child.second;
            if (dis[currv] + wt < dis[childV])
            {
                dis[childV] = dis[currv] + wt;
                st.insert({dis[childV], childV});
            }
        }
    }
    for(int i=1; i<=n; ++i){
        ans=max(ans, dis[i]);
    }
    return ans!=1e9? ans: -1;
}
