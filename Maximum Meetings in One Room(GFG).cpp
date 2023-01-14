#include <bits/stdc++.h>
using namespace std;
// Maximum Meetings in One Room(GFG)
static bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{

    if (a.second == b.second)
        return a.first.second < b.first.second;

    return a.second < b.second;
}
vector<int> maxMeetings(int n, vector<int> &start, vector<int> &end)
{
    vector<int> ans;
    vector<pair<pair<int, int>, int>> v;

    for (int i = 0; i < n; i++)
    {

        v.push_back({{start[i], i + 1}, end[i]});
    }

    sort(v.begin(), v.end(), cmp);

    int prevWorkingDay = v[0].second;
    ans.push_back(v[0].first.second);
    int i = 1;
    while (i < n)
    {
        if (prevWorkingDay < v[i].first.first)
        {
            ans.push_back(v[i].first.second);
            prevWorkingDay = v[i].second;
        }
        i++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}
