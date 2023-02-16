#include <bits/stdc++.h>
using namespace std;
// Longest Well-Performing Interval(LeetCode)
int longestWPI(vector<int> &hours)
{
	int n = hours.size(), sm = 0, ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (hours[i] > 8)
		{
			hours[i] = 1;
		}
		else
		{
			hours[i] = -1;
		}
	}
	unordered_map<int, int> firstSeen;
	for (int i = 0; i < n; ++i)
	{
		sm += hours[i];
		if (sm > 0)
		{
			ans = max(ans, i + 1);
		}
		else
		{
			if (firstSeen.count(sm - 1))
			{
				ans = max(ans, i - firstSeen[sm - 1]);
			}
		}
		if (firstSeen.find(sm) == firstSeen.end())
		{
			firstSeen[sm] = i;
		}
	}
	return ans;
}
