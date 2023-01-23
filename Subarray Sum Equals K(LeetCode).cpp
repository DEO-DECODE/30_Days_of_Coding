// Subarray Sum Equals K(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    int n=nums.size();
    unordered_map<int, int> mp;
    int sm=0;
    int ans=0;
    mp[0]++;
    for(int i=0; i<n; ++i){
        if(mp[sm-k]!=0){
            ans+=mp[sm-k];
        }
        sm+=nums[i];
        mp[sm]++;
    }
    return ans;
}
