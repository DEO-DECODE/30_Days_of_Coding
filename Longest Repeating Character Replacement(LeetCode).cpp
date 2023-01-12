#include <bits/stdc++.h>
using namespace std;
/*
Longest Repeating Character Replacement(LeetCode)
*/
int characterReplacement(string s, int k)
{
    unordered_map<char, int> freq;
    int mostFreqLetter = 0;
    int j = 0;
    int maxm = 0;

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]++;
        mostFreqLetter = max(mostFreqLetter, freq[s[i]]);
        int lettersToChange = (i - j + 1) - mostFreqLetter;
        // These are the letters that are needed to be changed.
        if (lettersToChange > k)
        {
            freq[s[j]]--;
            j++;
        }

        maxm = max(maxm, i - j + 1);
    }

    return maxm;
}
