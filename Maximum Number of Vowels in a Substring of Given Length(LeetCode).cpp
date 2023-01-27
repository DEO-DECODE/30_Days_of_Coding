// Maximum Number of Vowels in a Substring of Given Length(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int maxVowels(string s, int k)
{
    unordered_map<char, int> vowel;
    vowel['a'] = 1;
    vowel['e'] = 1;
    vowel['i'] = 1;
    vowel['o'] = 1;
    vowel['u'] = 1;
    int ans = 0, cnt = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        cnt += vowel[s[i]];
        if (i >= k)
            cnt -= vowel[s[i - k]];
        ans = max(ans, cnt);
    }
    return ans;
}
