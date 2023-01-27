// Minimum Operations to Reduce X to Zero(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum==x) return nums.size();
    int SumAllowed = totalSum - x;
    int j = 0, i = 0, n = nums.size();
    int sm = 0;
    int minm = INT_MAX;
    for (i = 0; i < n; ++i)
    {
        sm += nums[i];
        while (j < i && sm > SumAllowed)
        {
            // cout << i << " " << j << endl;
            sm -= nums[j];
            j++;
        }
        if (sm == SumAllowed && n - (i - j + 1) < minm)
        {
            minm = n - (i - j + 1);
        }
    }
    if (sm == SumAllowed && n - (i - j + 1) < minm)
        {
            minm = n - (i-1 - j + 1);
        }
    if (minm == INT_MAX)
        return -1;
    return minm;
    }
