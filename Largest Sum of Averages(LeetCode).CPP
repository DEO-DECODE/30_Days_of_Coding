#include <bits/stdc++.h>
using namespace std;
// Largest Sum of Averages(LeetCode)
double f(int ind, int k, vector<vector<double>> &dp, vector<int> &nums)
{
	// Out of Bound check.
	if (k <= 0)
		return 0;
	// If we have calculated it before then we simply need to return it.
	if (dp[ind][k] != -1)
		return dp[ind][k];
	double ans = 0, sum = 0;
	for (int i = ind; i < nums.size(); ++i)
	{
		sum += nums[i];
		if (k != 1 || i == nums.size() - 1)
			ans = max(ans, sum / (i - ind + 1) + f(i + 1, k - 1, dp, nums));
	}
	return dp[ind][k] = ans;
}
double largestSumOfAverages(vector<int> &nums, int k)
{
	int n = nums.size();
	vector<vector<double>> dp(n + 1, vector<double>(k + 1, -1));
	return f(0, k, dp, nums);
}
