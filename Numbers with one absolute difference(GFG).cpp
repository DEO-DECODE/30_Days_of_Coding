// Numbers with one absolute difference(GFG)
#include <bits/stdc++.h>
using namespace std;
void dfs(set<long long> &ans, long long value, long long N)
{
    if (value > N)
        return;
    if (value > 9)
    {
        ans.insert(value);
    }
    int lastDigit = value % 10;
    if (lastDigit != 0)
    {
        dfs(ans, value * 10 + (lastDigit - 1), N);
    }
    if (lastDigit != 9)
    {
        dfs(ans, value * 10 + (lastDigit + 1), N);
    }
}
vector<long long> absDifOne(long long N)
{
    set<long long> ans;
    for (int i = 1; i <= 9; ++i)
    {
        dfs(ans, i, N);
    }
    vector<long long> orgAns;
    for (auto val : ans)
    {
        orgAns.push_back(val);
    }
    return orgAns;
}
