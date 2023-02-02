#include <bits/stdc++.h>
using namespace std;
// Product of Array Except Self(LeetCode)
vector<int> productExceptSelf(vector<int> &nums)
{
    int n=nums.size();
    vector<int> ans(n,1);
    int suffProd=1;
    // Initially we are storing the product of elements from left to the index before , as we are told to exclude self.
    for(int i=1; i<n; ++i){
        ans[i]=ans[i-1]*nums[i-1];
    }
    // Now we will calculate the product of elements from last to index after it.
    for(int i=n-1; i>=0; --i){
        ans[i]=ans[i]*suffProd;
        suffProd=suffProd*nums[i];
    }
    return ans;
}
