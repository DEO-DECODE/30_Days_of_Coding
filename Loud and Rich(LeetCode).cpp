// Loud and Rich(LeetCode).
#include <bits/stdc++.h>
using namespace std;
/*
For any person, we look for all the person who is equally rich or richer than them and then we select the quietest among these set of richer people.
Example: Richness order: x>y, z>y, w>v. Then we can't decide who is the richest among x,z & w b/c we don't have proper information regarding their comparison. So we assume that all of them are richest.
For any 'a' who is richest we don't have any 'b' who is richer or equally rich, so we have only 'a' himself the only candidate to be checked for quietest so ans[a] = a.
Thus we use topological sort here in such a way that richest are the least dependent (no indegree)

Then the lesser rich will see if the ans of richer one is quieter than his ans(no comparison of richness b/c richness order: ans[richer] >= richer & richer >= lesser rich so obviously ans[richer] >= lesser rich). If yes then he will replace his answer with the ans[richer].
*/
vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
{
    int n = quiet.size();
    vector<int> ans(n, INT_MAX), inDeg(n, 0);
    vector<vector<int>> graph(n);
    for (auto edge : richer)
    {
        graph[edge[0]].push_back(edge[1]);
        inDeg[edge[1]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        ans[i] = i;
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size() > 0)
    {
        auto par = q.front();
        q.pop();
        for (auto child : graph[par])
        {
            if (quiet[ans[child]] > quiet[ans[par]])
            {
                ans[child] = ans[par];
            }
            inDeg[child]--;
            if (inDeg[child] == 0)
            {
                q.push(child);
            }
        }
    }
    return ans;
}
