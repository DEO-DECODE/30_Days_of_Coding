//Continuous Subarray Sum(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size(), ans = 0;
    int summation = 0;
    int rem;
    // vector<int> prefixSum(n,0);
    unordered_map<int, vector<int>> remainderFrequency;
    remainderFrequency[0].push_back(-1);
    for (int i = 0; i < n; ++i)
    {
        summation += nums[i];
        rem = summation % k;
        if (rem < 0)
        {
            rem += k;
        }
        if (remainderFrequency[rem].size()>0)
        {
            if (i - remainderFrequency[rem][0] >= 2)
                return true;
        }
        remainderFrequency[rem].push_back(i);
    }
    return ans;
}
