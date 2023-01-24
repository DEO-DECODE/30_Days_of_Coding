#include <bits/stdc++.h>
using namespace std;
// Maximum Number of Occurrences of a Substring(LeetCode)
int maxFreq(string s, int maxLetters, int minSize, int maxSize)
{
    unordered_map<char, int> mp;
    unordered_map<string, int> subStrings;
    int j = 0, currLen = 0, numDistinct = 0, maxmO = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        mp[s[i]]++;
        while (i - j + 1 > maxLetters || mp.size() > maxLetters)
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
            {
                mp.erase(mp.find(s[j]));
            }
            j++;
        }
        if (i - j + 1 == minSize && i - j + 1 <= maxSize && mp.size() <= maxLetters)
        {
            maxmO = max(maxmO, ++subStrings[s.substr(j, j - i + 1)]);
        }
    }
    return maxmO;
}
