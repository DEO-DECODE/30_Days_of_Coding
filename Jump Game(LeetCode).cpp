#include <bits/stdc++.h>
using namespace std;
// Jump Game(LeetCode)
bool jumps(vector<int> &nums, int ind, vector<int> &dp)
{
    if (ind == nums.size() - 1)
    {
        return true;
    }
    if (nums[ind] == 0)
        return false;
    if (dp[ind] != -1)
        return dp[ind];
    bool orgAns = false;
    int reach = ind + nums[ind];
    for (int jump = ind + 1; jump <= reach; jump++)
    {
        if (jump < nums.size() && jumps(nums, jump, dp))
        {
            return dp[ind] = true;
        } // memoizing for particular index.
    }
    return dp[ind] = false;
}
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    bool answer = jumps(nums, 0, dp);
    return answer;
}
