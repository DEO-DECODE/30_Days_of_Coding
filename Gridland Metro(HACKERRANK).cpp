// Gridland Metro(HACKERRANK)
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> merge(vector<pair<int, int>> &v)
{
    vector<pair<int, int>> merged;
    if (v.size() != 0)
    {
        sort(v.begin(), v.end());
    }
    stack<pair<int, int>> st;
    st.push(v[0]);
    for (int i = 1; i < v.size(); ++i)
    {
        auto topPair = st.top();
        if (v[i].first > topPair.second)
        {
            st.push(v[i]);
        }
        else if (v[i].first <= topPair.second)
        {
            topPair.second = max(topPair.second, v[i].second);
            st.pop();
            st.push(topPair);
        }
    }
    while (!st.empty())
    {
        merged.push_back(st.top());
        st.pop();
    }
    return merged;
}
int main()
{
    map<int, vector<pair<int, int>>> mp;
    int n, m, k;
    for (int i = 0; i < k; ++i)
    {
        int r, c1, c2;
        cin >> r >> c1 >> c2;
        mp[r].push_back({c1, c2});
    }
    long long ans = ((long long)n) * ((long long)m);
    for (auto &node : mp)
    {
        node.second = merge(node.second);
        int sz = node.second.size();
        for (int i = 0; i < sz; ++i)
        {
            ans -= (node.second[i].second - node.second[i].first + 1);
        }
    }
    cout << ans << endl;
}
