// Bob and his special string(HackerEarth)
#include <bits/stdc++.h>
using namespace std;
bool isPossible(int mid, unordered_map<char, int> &freqMap, int n)
{
	if (mid == 0)
		return false;
	int ReqLength = 0;
	/*
	If a character rrepeats x number of times in the original string , then it must repeat ceiling of
	x/mid times in the modified string.
	*/

	for (auto pr : freqMap)
	{
		ReqLength += ((pr.second) + mid - 1) / mid;
		if (ReqLength > n)
			return false;
	}
	return true;
}
int minim(string &orgStr, int n)
{
	unordered_map<char, int> freq;
	for (char ch : orgStr)
		freq[ch]++;
	int lo = 0, hi = orgStr.size();
	int ans = INT_MAX;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (isPossible(mid, freq, n))
		{
			ans = min(ans, mid);
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	return ans;
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << minim(s, n);
    return 0;
}
