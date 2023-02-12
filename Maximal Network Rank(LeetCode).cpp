// Maximal Network Rank(LeetCode).
#include <bits/stdc++.h>
using namespace std;
int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    vector<unordered_set<int>> graph(n);
    for (auto edge : roads)
    {
        graph[edge[0]].insert(edge[1]);
        graph[edge[1]].insert(edge[0]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int cnt=0;
        for(int j=i+1; j<n; ++j){
            cnt=graph[i].size()+graph[j].size();
            auto st=graph[i];
            auto itr=st.find(j);
            if(itr!=st.end()) cnt--;
            ans=max(ans, cnt);
        }
    }
    return ans;
}
