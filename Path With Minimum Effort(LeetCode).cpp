// Path With Minimum Effort(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int minimumEffortPath(vector<vector<int>> &heights)
{
    int m = heights.size(), n = heights[0].size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    q.push({0, 0, 0});
    while (!q.empty())
    {
        vector<int> v = q.top();
        q.pop();
        int eff = v[0], x = v[1], y = v[2];
        if (x == m - 1 && y == n - 1)
            return eff;
        if (heights[x][y] == 0)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int childx = x + dx[i], childy = y + dy[i];
            if (childx <= m - 1 && childy <= n - 1 && childx >= 0 && childy >= 0)
                q.push({max(eff, abs(heights[x][y] - heights[childx][childy])), childx, childy});
        }
        heights[x][y] = 0;
    }
    return 0;
}
