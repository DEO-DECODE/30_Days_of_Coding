#include <bits/stdc++.h>
using namespace std;
// Corporate Flight Bookings(LeetCode)
vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
	vector<int> ans(n, 0);
	for (auto vec : bookings)
	{
		int iind = vec[0] - 1;
		int jind = vec[1];
		int seats = vec[2];
		// Number of bookings starting from flight iind.
		ans[iind] += seats;
		if (jind != n)
		{
			ans[jind] -= seats;
		}
	}
	for (int i = 0; i < n - 1; ++i)
	{
		ans[i + 1] += ans[i];
	}
	return ans;
}
