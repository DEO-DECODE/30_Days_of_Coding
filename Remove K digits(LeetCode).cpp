// Remove K digits(LeetCode)
#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k)
{
    stack<char> st;
    int n=num.size();
    for (int i = 0; i < num.size(); ++i)
    {
        while (k > 0 && !st.empty() && num[i] < st.top())
        {
            st.pop();
            k--;
        }
        if (st.empty() && num[i] == '0')
            continue;
        st.push(num[i]);
    }
    while ((!st.empty() && k--))
    {
        st.pop();
    }
    if (st.empty())
        return "0";
    while (!st.empty())
    {
        num[n - 1] = st.top();
        st.pop(), n--;
    }
    return num.substr(n);
}
