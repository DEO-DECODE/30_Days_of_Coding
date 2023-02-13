//Uncrossed Lines(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int f(int ind1, int ind2, vector<vector<int>> &dp, vector<int> &nums1, vector<int> &nums2, int n, int m){
    if(ind1==n||ind2==m) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    // case of match
    int match=0, notmatch=0;
    if(nums1[ind1]==nums2[ind2]){
        match=1+f(ind1+1, ind2+1, dp, nums1, nums2, n,m);
    }
    else{
        notmatch=max(f(ind1, ind2+1, dp, nums1, nums2, n, m), f(ind1+1, ind2, dp, nums1, nums2, n, m));
    }
    return dp[ind1][ind2]=max(match, notmatch);
}
int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
{
    int n=nums1.size(), m=nums2.size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return f(0, 0, dp, nums1, nums2, n, m);
}
