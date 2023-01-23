#include <bits/stdc++.h>
using namespace std;
// Grumpy Bookstore Owner(LeetCode)
int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
{
    int n = customers.size();
    vector<int> prefixsum(n+1, 0), suffixsum(n+1, 0);
    int sm = 0;
    for (int i = 0; i < n; ++i)
    {
        if (grumpy[i] == 0)
        {
            sm += customers[i];
        }
        prefixsum[i] = sm;
    }
    sm = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (grumpy[i] == 0)
        {
            sm += customers[i];
        }
        suffixsum[i] = sm;
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << prefixsum[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << suffixsum[i] << " ";
    // }
    // cout << endl;
    // Applying Sliding Window
    int ans=0, slidingWindowSum=0;
    int i=0;
    for(i=0; i<minutes; ++i){
        slidingWindowSum+=customers[i];
    }
    ans=max(ans, slidingWindowSum+suffixsum[i]);
    while (i<n)
    {
        // acquire
        slidingWindowSum+=customers[i];
        // release
        slidingWindowSum-=customers[i-minutes];
        int currSum=slidingWindowSum+suffixsum[i+1]+prefixsum[i-minutes];
        ans=max(ans, currSum);
        i++;
    }
    
    return ans;
}
int main()
{
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5}, grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    cout<<maxSatisfied(customers,grumpy,3);
}
