//Number of Substrings Containing All Three Characters(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s)
{
    unordered_map<char, int> freq;
    int j = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        freq[s[i]]++;
        while (freq['a'] >= 1 && freq['b'] >= 1 && freq['c'] >= 1)
        {
            freq[s[j]]--;
            j++;
            ans += (s.size() - i);
        }
    }
    return ans;
}
