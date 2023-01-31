// Remove Duplicate Letters(LeetCode)
#include <bits/stdc++.h>
using namespace std;
string removeDuplicateLetters(string s)
{
    stack<char> st;
    unordered_map<char, int> lastOccurence, used;
    for (int i = 0; i < s.size(); ++i)
    {
        lastOccurence[s[i]] = i;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        char curr = s[i];
        while (used[curr]==0&&!st.empty() && curr < st.top() && lastOccurence[st.top()] > i)
        {
            used[st.top()] = 0;
            st.pop();
        }
        if(used[curr]==0)
        st.push(curr);
        used[curr] = 1;
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
