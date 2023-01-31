// ThreeSum(LeetCode)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    // nums[i]+nums[j]+nums[k]=0
    for (int i = 0; i < nums.size() - 2; ++i)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int lo = i + 1, hi = nums.size() - 1;
            int target = -nums[i];
            while (lo < hi)
            {
                if (nums[lo] + nums[hi] == target)
                {
                    vector<int> temp;
                    temp = {nums[i], nums[lo], nums[hi]};
                    ans.push_back(temp);
                    while (lo < hi && nums[lo] == nums[lo + 1])
                    {
                        lo++;
                    }
                    while (lo < hi && nums[hi] == nums[hi - 1])
                    {
                        hi--;
                    }
                    lo++, hi--;
                }
                else if(nums[lo]+nums[hi]<target){
                    lo++;
                }
                else{
                    hi--;
                }
            }
        }
    }
    return ans;
}
