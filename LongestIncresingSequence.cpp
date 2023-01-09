#include<bits/stdc++.h>
using namespace std;
int f(int ind, int prev, vector<vector<int>> &dp, vector<int> &nums, int n)
    {
        if (ind == n)
            return 0;
        if (dp[ind][prev+1] != -1)
            return dp[ind][prev+1];
        // Not take
        int len = 0 + f(ind + 1, prev, dp, nums, n);
        // Take
        if (prev == -1 || nums[ind] > nums[prev])
        {
            len = max(len, 1 + f(ind + 1, ind, dp, nums, n));
        }
        return dp[ind][prev + 1] = len;
    }
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, dp, nums, n);
}
