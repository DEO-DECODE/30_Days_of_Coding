// FourSum(LeetCode)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    if (nums.size() < 4)
        return ans;
    for (int i = 0; i < nums.size() - 3; ++i)
    {
        long long target_3 = target - nums[i];
        for (int j = i + 1; j < nums.size(); ++j)
        {
            long long target_2 = target_3 - nums[j];
            int lo = j + 1;
            int hi = nums.size() - 1;
            while (lo < hi)
            {
                if (nums[lo] + nums[hi] == target_2)
                {
                    vector<int> temp = {nums[i], nums[j], nums[lo], nums[hi]};
                    ans.push_back(temp);
                    while (lo < hi && (nums[lo] == nums[lo + 1]))
                        lo++;
                    while (lo < hi && (nums[hi] == nums[hi - 1]))
                        hi--;
                    lo++;
                    hi--;
                }
                else if (nums[lo] + nums[hi] < target_2)
					lo++;
				else
					hi--;
            }
            while (j + 1 < nums.size() && nums[j + 1] == nums[j])
				++j;
        }
        while (i + 1 < nums.size() && nums[i + 1] == nums[i])
			++i;
    }
    return ans;
}
