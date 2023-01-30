// Container With Most Water(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int> &height)
{
    /*
    The basic idea is that widest container will hold the maximum amount of water due to larger base width
    so if we want to shrink the width then it can be managed by increasing height level , therefore out of both the pointers the pointer will move towards the larger height
    */
    int i = 0;
    int j = height.size() - 1;
    int ans = 0;
    while (i < j)
    {
        ans = max(ans, (j - i) * min(height[i], height[j]));
        if (height[i] > height[j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return ans;
}
