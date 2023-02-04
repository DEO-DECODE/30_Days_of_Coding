// Minimum Height Trees(LeetCode)
#include <bits/stdc++.h>
using namespace std;
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(n);
    vector<int> inDegrees(n, 0), ans;
    if(n==1){
        ans.push_back(0);
        return ans;
    }
    for (auto edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
        inDegrees[edge[0]]++, inDegrees[edge[1]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        if (inDegrees[i] == 1)
        {
            q.push(i);
            inDegrees[i]--;
        }
    }
    while (q.size() > 0)
    {
        int sz = q.size();
        ans.clear();
        while (sz--)
        {
            int currv = q.front();
            q.pop();
            ans.push_back(currv);
            for (auto child : graph[currv])
            {
                inDegrees[child]--;
                if (inDegrees[child] == 1)
                    q.push(child);
            }
        }
    }
    return ans;
}
