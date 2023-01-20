#include <bits/stdc++.h>
using namespace std;
//Maximum Average Subarray I(LeetCode)
double findMaxAverage(vector<int>& nums, int k) {
    int n=nums.size();
    double sm=0;
    double ans=0;
    for(int i=0; i<k; ++i){
        sm+=nums[i];
    }        
    // ans=max(ans, sm);
    for(int i=k; i<n; ++i){
        ans=max(ans,sm);
        // acquire
        sm+=nums[i];
        // release
        sm-=nums[i-k];
    }
    ans=max(ans, sm);
    return ans/k;
}
