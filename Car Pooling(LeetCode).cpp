#include <bits/stdc++.h>
using namespace std;
// Car Pooling(LeetCode)
bool cmp(vector<int> &a, vector<int> &b)
{
	if (a[1] != b[1])
		return a[1] < b[1];
	else if (a[1] == b[1] && a[2] != b[2])
		return a[2] < b[2];
	else
		return a[0] > b[0];
}
bool carPooling(vector<vector<int>> &trips, int capacity)
{
	// We should sort the trips based on initial position of the passengers and if the initialPosition is same then we will simply sort according to lesser destination.
	int n = trips.size();
	map<int, int> starting, ending;
	for (auto vec : trips)
	{
		starting[vec[1]] += vec[0];
	}
	for (auto vec : trips)
	{
		ending[vec[2]] += vec[0];
	}
	// for (auto val : starting)
	// {
	// 	cout << val.first << " " << val.second << endl;
	// }
	// cout << "\n\n";
	// for (auto val : ending)
	// {
	// 	cout << val.first << " " << val.second << endl;
	// }
	auto itr = starting.begin(), itr2 = ending.begin();
	int currOccupied = 0;
	while (itr != starting.end() && itr2 != ending.end())
	{
		cout << currOccupied << " " << (*itr).first << " " << (*itr2).first << endl;
		if ((*itr2).first <= (*itr).first)
		{
			currOccupied -= (*itr2).second;
			itr2++;
		}
		else
		{
			currOccupied += (*itr).second;
			itr++;
		}
		// currOccupied += (*itr).second;
		
		if (currOccupied > capacity)
			return false;
	}
	return true;
}
int main()
{
	vector<vector<int>> trips = {{2, 1, 9},
								 {3, 4, 7},
								 {4, 7, 9},
								 {5, 9, 11}};
	cout << carPooling(trips, 6);
}
