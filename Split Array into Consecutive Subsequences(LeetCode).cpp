#include <bits/stdc++.h>
using namespace std;
//659. Split Array into Consecutive Subsequences(LeetCode)
bool isPossible(vector<int> &nums)
{
    /* For every number in the nums vector , there are two choices , either to become the part of any ongoing sequence or It can start a new subsequence starting from that number.
    if it can't start the subsequence in case If no one needs it then simply return false
    */
    unordered_map<int, int> freq;
    unordered_map<int, int> need;
    for (auto x : nums)
        freq[x]++;
    for (auto num : nums)
    {
        if (freq[num] == 0)
            continue;
        if (need[num] > 0)
        {
            need[num]--;
            need[num + 1]++;
            freq[num]--;
        }
        else if (freq[num] > 0 && freq[num + 1] > 0 && freq[num + 2] > 0)
        {
            freq[num]--;
            freq[num + 1]--;
            freq[num + 2]--;
            need[num + 3]++;
        }
        else
        {
            return false;
        }
    }
    return true;
}
