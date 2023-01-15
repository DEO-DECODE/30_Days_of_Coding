#include <bits/stdc++.h>
using namespace std;
// Split Array Largest Sum(LEETCODE)
int numSubarraysMid(vector<int> &nums, int mid)
{
    int sum = 0, cnt = 1;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (sum + nums[i] > mid)
        {
            cnt++;
            sum = nums[i];
        }
        else
            sum += nums[i];
    }
    return cnt;
}
int splitArray(vector<int> &nums, int k)
{
    int lo = (*max_element(nums.begin(), nums.end()));
    int hi = accumulate(nums.begin(), nums.end(), 0);
    if (k == 1)
        return hi;
    int ans = lo;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int numPartition_req = numSubarraysMid(nums, mid);
        if(numPartition_req>k){
            lo=mid+1;
        }
        else{
            ans=mid;
            hi=mid-1;
        }
    }
    return ans;
}
