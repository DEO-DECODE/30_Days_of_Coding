#include <bits/stdc++.h>
using namespace std;
 vector<string> ans;
map<string, multiset<string>> mp;
void dfs(string src)
{
    while (mp[src].size() > 0)
    {
        string next = *mp[src].begin();
        mp[src].erase(mp[src].begin());
        dfs(next);
    }
    ans.push_back(src);
}
vector<string> findItinerary(vector<vector<string>> &tickets)
{
    for (int i = 0; i < tickets.size(); ++i)
    {
        mp[tickets[i][0]].insert(tickets[i][1]);
    }
    // mp formed
    dfs("JFK");
    // sort(ans.begin(), ans.end());
    return vector<string>(ans.rbegin(), ans.rend());
}
