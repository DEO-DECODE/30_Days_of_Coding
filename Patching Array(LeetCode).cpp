// Patching Array(LeetCode)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        long long index = 0, reach = 0, cnt = 0;
        while (reach < n)
        {
            if (index >= nums.size())
            {
                reach += (reach + 1);
                cnt++;
            }
            else if (index < nums.size() && nums[index] <= (reach + 1))
            {
                reach += (nums[index]);
                index++;
            }
            else
            {
                reach += (reach + 1);
                cnt++;
            }
        }
        return cnt;
    }
};
