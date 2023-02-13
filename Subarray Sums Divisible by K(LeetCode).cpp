// Subarray Sums Divisible by K(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int subarraysDivByK(vector<int> &nums, int k)
{
    int n=nums.size(), ans=0;
    int summation=0;
    int rem;
    // vector<int> prefixSum(n,0);
    unordered_map<int, int> remainderFrequency;
    remainderFrequency[0]++;
    for(int i=0; i<n; ++i){
        summation+=nums[i];
        rem=summation%k;
        if(rem<0){
            rem+=k;
        }
        if(remainderFrequency.count(rem)){
            ans+=remainderFrequency[rem];
        }
        remainderFrequency[rem]++;
    }
    return ans;
}
