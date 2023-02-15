#include <bits/stdc++.h>
using namespace std;
// Contiguous Array(LeetCode)
int findMaxLength(vector<int> &nums)
{
	unordered_map<int, int> sumFreq;
	int n = nums.size(), ans = 0;
	int sm = 0;
	sumFreq[sm] = -1;
	for (int i = 0; i < n; ++i)
	{
		if (nums[i] == 0)
		{
			sm += -1;
		}
		else if(nums[i]==1)
		{
			sm += 1;
		}
		if (sumFreq.count(sm))
		{
			ans = max(ans, i - sumFreq[sm]);
		}
		else
		{
			sumFreq[sm]=i;
		}
	}
	return ans;
}
