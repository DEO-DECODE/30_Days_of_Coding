#include <bits/stdc++.h>
using namespace std;
int findUnsortedSubarray(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low + 1 < nums.size() && nums[low] <= nums[low + 1])
        low++;
    while (high - 1 >= 0 && nums[high - 1] <= nums[high])
        high--;
    int minmele = INT_MAX;
    int maxmele = INT_MIN;
    for (int i = low; i <= high; ++i)
    {
        minmele = min(minmele, nums[i]);
        maxmele = max(maxmele, nums[i]);
    }
    if (low == nums.size() - 1)
        return 0;
    while (low - 1 >= 0 && nums[low - 1] > minmele)
        low--;
    while (high + 1 < nums.size() && nums[high + 1] < maxmele)
        high++;
    return high - low + 1;
}
