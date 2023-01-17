#include <bits/stdc++.h>
using namespace std;
// 611. Valid Triangle Number(LeetCode)
int triangleNumber(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int i = 0;
    int ans = 0;
    for (int k = n - 1; k >= 2; --k)
    {
        int i = 0, j = k - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] > nums[k])
            {
                ans += j - i;
                j -= 1;
            }
            else
            {
                i += 1;
            }
        }
        i = 0;
    }
    return ans;
}
