#include <bits/stdc++.h>
using namespace std;
// Binary Subarrays With Sum(LeetCode)
int numSubarraysWithSum(vector<int> &nums, int goal)
{

	int n = nums.size();
	int sm = 0, ans = 0;
	unordered_map<int, int> mp;
	mp[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		sm += nums[i];
		if (mp[sm - goal] > 0)
		{
			ans += mp[sm - goal];
		}
		mp[sm]++;
	}
	return ans;
}
