#include <bits/stdc++.h>
using namespace std;
// Combination Sum II(LeetCode)
void allPossible(int ind, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &curr)
{
    if (target == 0)
    {
        ans.push_back(curr);
        return;
    }
    if (ind == candidates.size())
    {
        return;
    }
    // Pick
    if (candidates[ind] <= target)
    {
        curr.push_back(candidates[ind]);
        allPossible(ind + 1, target - candidates[ind], candidates, ans, curr);
        curr.pop_back();
    }
    // Not Pick
    while (ind < candidates.size() && candidates[ind] == candidates[ind + 1])
    {
        ind++;
    }
    allPossible(ind + 1, target, candidates, ans, curr);
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> curr;
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    allPossible(0, target, candidates, ans, curr);
    return ans;
}
