#include <bits/stdc++.h>
using namespace std;
// Maximum Sum of Two Non-Overlapping Subarrays(LeetCode)
int func(vector<int> &nums, int firstLen, int secondLen)
{
    int n = nums.size();
    vector<int> dp1(n, 0), dp2(n, 0);
    int sm = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i < firstLen)
        {
            sm += nums[i];
            dp1[i] = sm;
        }
        else
        {
            sm+=nums[i]-nums[i-firstLen];
            dp1[i] = max(dp1[i-1], sm);
        }
    }
    sm = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (i > n - secondLen - 1)
        {
            sm += nums[i];
            dp2[i] = sm;
        }
        else
        {
            sm+=nums[i]-nums[i+secondLen];
            dp2[i] = max(dp2[i+1], sm);
        }
    }
    int maxm = 0;
    for (int i = firstLen - 1; i < n - secondLen; ++i)
    {
        maxm = max(maxm, dp1[i] + dp2[i + 1]);
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << dp1[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << dp2[i] << " ";
    // }
    // cout << "\n\n";

    return maxm;
}
int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen)
{
    int sm1 = func(nums, firstLen, secondLen);
    int sm2 = func(nums, secondLen, firstLen);
    return max(sm1, sm2);
}
int main()
{
    vector<int> nums = {2, 1, 5, 6, 0, 9, 5, 0, 3, 8};
    cout << maxSumTwoNoOverlap(nums, 4, 3) << endl;
}
