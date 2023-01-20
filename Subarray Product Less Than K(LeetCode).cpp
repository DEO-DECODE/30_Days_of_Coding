#include <bits/stdc++.h>
using namespace std;
// Subarray Product Less Than K(LeetCode)
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int prod = 1, n = nums.size(), i = 0, cnt = 0;
    int j = 0;

    while (i < n)
    {
        prod *= nums[i];
        while (j <= i && prod >= k)
        {
            prod = prod / nums[j];
            j++;
        }
        cnt += (i - j + 1);
        i++;
    }
    return cnt;
}
