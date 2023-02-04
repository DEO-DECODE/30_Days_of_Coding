//Russian Doll Envelopes(LeetCode)
#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}
int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), cmp);
    vector<int> temp;
    temp.push_back(envelopes[0][1]);

    for (int i = 1; i < envelopes.size(); i++)
    {
        int height = envelopes[i][1];
        if (height > temp.back())
        {
            temp.push_back(height);
        }
        else
        {
            auto it = lower_bound(temp.begin(), temp.end(), height);
            *it = height;
        }
    }
    return temp.size();
}
int main()
{
    vector<vector<int>> envalopes = {{2, 7}, {3, 4}, {4, 6}, {4, 9}, {1, 8}, {5, 3}, {5, 6}};
    int x = maxEnvelopes(envalopes);
    cout << x << endl;
}
