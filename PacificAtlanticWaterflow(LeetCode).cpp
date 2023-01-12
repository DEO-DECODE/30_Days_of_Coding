#include <bits/stdc++.h>
// Pacific Atlantic WaterFlow(LeetCode)
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void dfs(vector<vector<int>> &heights, int r, int c, int prev, vector<vector<int>> &ocean)
{
    if (r < 0 || r >= heights.size())
        return;
    if (c < 0 || c >= heights[0].size())
        return;
    // Out of bound condition shold be written first.
    if (ocean[r][c] == 1)
    {
        return;
    }
    if (heights[r][c] < prev)
    {
        return;
    }
    ocean[r][c] = 1;
    for (int i = 0; i < 4; ++i)
    {
        int childx = r + dx[i];
        int childy = c + dy[i];
        dfs(heights, childx, childy, heights[r][c], ocean);
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    // Traversing the coast of pacific ocean.
    vector<vector<int>> pacific(heights.size(), vector<int>(heights[0].size(), -1));
    for (int i = 0; i < heights.size(); ++i)
    {
        dfs(heights, i, 0, -5, pacific);
    }
    for (int j = 0; j < heights[0].size(); ++j)
    {
        dfs(heights, 0, j, -5, pacific);
    }
    // Traversing the coast of Atlantic ocean.
    vector<vector<int>> atlantic(heights.size(), vector<int>(heights[0].size(), -1));
    for (int i = 0; i < heights.size(); ++i)
    {
        dfs(heights, i, heights[0].size() - 1, -5, atlantic);
    }
    for (int j = 0; j < heights[0].size(); ++j)
    {
        dfs(heights, heights.size() - 1, j, -5, atlantic);
    }
    vector<vector<int>> ans;
    for (int i = 0; i < heights.size(); ++i)
    {
        for (int j = 0; j < heights[0].size(); ++j)
        {
            if (pacific[i][j] == 1 && atlantic[i][j] == 1)
            {
                vector<int> temp = {i, j};
                ans.push_back(temp);
            }
        }
    }
    return ans;
}
