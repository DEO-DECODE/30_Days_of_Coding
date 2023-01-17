#include <bits/stdc++.h>
using namespace std;
// 455. Assign Cookies(LeetCode)
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(s.begin(), s.end());
    sort(g.begin(), g.end());
    int cnt = 0;
    for (int i = 0; i < g.size(); ++i)
    {
        auto low1 = lower_bound(s.begin(), s.end(), g[i]) - s.begin();
        if (low1 < s.size())
        {
            cnt++;
            s.erase(find(s.begin(), s.end(), s[low1]));
        }
    }
    return cnt;
}
