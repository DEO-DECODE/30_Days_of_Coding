// Shortest Subarray with Sum at Least K(LeetCode)
#include <bits/stdc++.h>
using namespace std;
/*
-10^5 <= nums[i] <= 10^5
1 <= k <= 109
*/
int shortestSubarray(vector<int> &nums, int k)
{
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> dq;
    long long j = 0, sm = 0;
    long long ans = 1e18;
    for (long long i = 0; i < nums.size(); ++i)
    {
        sm += (long long)nums[i];
        if (sm >= k)
        {
            ans = min(ans, i + 1);
        }
        while (!dq.empty() && (sm - dq.top().first >= k))
        {
            auto pr = dq.top();
            dq.pop();
            ans = min(ans, i - pr.second);
        }
        dq.push({sm, i});
    }
    return ans == 1e18 ? -1 : ans;
}
