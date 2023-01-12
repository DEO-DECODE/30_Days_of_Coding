#include <bits/stdc++.h>
using namespace std;
//  Permutation in String(LeetCode)
bool checkInclusion(string s1, string s2)
{
    unordered_map<char, int> targetFreq;
    unordered_map<char, int> windowFreq;
    for (int i = 0; i < s1.size(); ++i)
    {
        targetFreq[s1[i]]++;
    }
    for (int i = 0; i < s1.size(); ++i)
    {
        windowFreq[s2[i]]++;
    }
    int i = s1.size();
    while (i < s2.size())
    {
        if (targetFreq == windowFreq)
        {
            return true;
        }
        // aquire
        windowFreq[s2[i]]++;
        // release
        windowFreq[s2[i - s1.size()]]--;
        if (windowFreq[s2[i - s1.size()]] == 0)
        {
            windowFreq.erase((windowFreq.find(s2[i - s1.size()])));
        }
        i++;
    }
    if (targetFreq == windowFreq)
    {
        return true;
    }
    return false;
}
