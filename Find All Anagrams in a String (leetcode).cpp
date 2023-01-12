#include <bits/stdc++.h>
using namespace std;
// Find All Anagrams in a String (leetcode)
bool cmp(unordered_map<char, int> pFreq, unordered_map<char, int> sFreq)
{
    for (auto val : sFreq)
    {
        if (pFreq[val.first] != val.second)
            return false;
    }
    return true;
}
vector<int> findAnagrams(string s, string p)
{
    unordered_map<char, int> pFreq;
    unordered_map<char, int> sFreq;
    vector<int> ans;
    for (int i = 0; i < p.size(); ++i)
    {
        pFreq[p[i]]++;
    }
    for (int i = 0; i < p.size(); ++i)
    {
        sFreq[s[i]]++;
    }
    int i = p.length();
    // vector<int> ans;
    while (i < s.size())
    {
        if (cmp(pFreq, sFreq))
        {
            ans.push_back(i - p.size());
        }
        // Acquire
        sFreq[s[i]]++;
        // Release
        sFreq[s[i - p.size()]]--;
        if (sFreq[s[i - p.size()]] == 0)
        {
            sFreq.erase(sFreq.find(s[i - p.size()]));
        }
        i++;
    }
    if (cmp(pFreq, sFreq))
    {
        ans.push_back(i - p.size());
    }
    return ans;
}
