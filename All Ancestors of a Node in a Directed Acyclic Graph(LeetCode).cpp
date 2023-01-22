// All Ancestors of a Node in a Directed Acyclic Graph(LeetCode)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
{
    vector<int> indegrees(n, 0);
    vector<vector<int>> ans(n);
    vector<int> adjacency[n + 1];
    for (int i = 0; i < edges.size(); ++i)
    {
        adjacency[edges[i][0]].push_back(edges[i][1]);
        indegrees[edges[i][1]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        if (indegrees[i] == 0)
        {
            q.push(i);
        }
    }
    map<int, set<int>> mp;
    while (q.size() > 0)
    {
        int currv = q.front();
        q.pop();
        for (auto child : adjacency[currv])
        {
            mp[child].insert(currv);
            for(auto ancs: mp[currv]){
                mp[child].insert(ancs);
            }
            indegrees[child]--;
            if (indegrees[child] == 0)
            {
                q.push(child);
            }
        }
    }
    for(auto entr: mp){
        for(auto val: entr.second){
            ans[entr.first].push_back(val);
        }
    }
    return ans;
}
