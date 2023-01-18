#include <bits/stdc++.h>
using namespace std;
//Maximum Length of Pair Chain(LeetCode)
bool cmp(vector<int> &v1, vector<int> &v2)
{
    if (v1[1] != v2[1])
        return v1[1] < v2[1];
    else
        return v1[0] < v2[0];
}
int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), cmp);
    int n = pairs.size();
    int maxm = 0;
    int prev = -10001;
    for (int i = 0; i < n; ++i)
    {
        if (pairs[i][0] > prev){
            maxm++;
            prev=pairs[i][1];
        }
    }
    return maxm;
}
