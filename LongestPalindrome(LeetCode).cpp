#include <bits/stdc++.h>
using namespace std;
int longestPalindrome(string s)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); ++i)
    {
        mp[s[i]]++;
    }
    multimap<int, char> mp2;
    for (auto val : mp)
    {
        mp2.insert({val.second, val.first});
    }
    bool oddSelected = false;
    auto itr = --mp2.end();
    int totalVal = 0;
    while (true)
    {
        if ((*itr).first % 2 == 0)
        {
            totalVal += (*itr).first;
        }
        else if (((*itr).first % 2 != 0) && (!oddSelected))
        {
            oddSelected = true;
            totalVal += (*itr).first;
        }
        else if (((*itr).first % 2 != 0) && (oddSelected))
        {
            totalVal += (*itr).first - 1;
        }
        if (itr == mp2.begin())
        {
            break;
        }
        itr--;
    }
    return totalVal;
}
