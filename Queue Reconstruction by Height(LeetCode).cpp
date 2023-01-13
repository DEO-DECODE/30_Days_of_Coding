#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &p1, vector<int> &p2)
{
    if(p1[0]!=p2[0]) return p1[0]>p2[0];
        else return p1[1]<p2[1];

}
vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
    sort(people.begin(), people.end(), cmp);
    vector<vector<int>> ans;
    for (auto vec : people)
    {
        ans.insert(ans.begin() + vec[1], vec);
    }
    return ans;
}
