// Maximum Length of Repeated Subarray(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int f(vector<int> &nums1, vector<int> &nums2, int ind1, int ind2, vector<vector<int>> &dp, int &ans)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    int temp = 0;
    if (nums1[ind1] == nums2[ind2])
        temp = 1 + f(nums1, nums2, ind1 - 1, ind2 - 1, dp, ans);
    f(nums1, nums2, ind1 - 1, ind2, dp, ans);
    f(nums1, nums2, ind1, ind2 - 1, dp, ans);
    return dp[ind1][ind2] = temp;
}
int findLength(vector<int> &nums1, vector<int> &nums2)
{
    int len1 = nums1.size(), len2 = nums2.size();
    vector<vector<int>> dp(len1, vector<int>(len2, -1));
    int ans = 0;
    int x = f(nums1, nums2, len1 - 1, len2 - 1, dp, ans);
    return ans;
}
