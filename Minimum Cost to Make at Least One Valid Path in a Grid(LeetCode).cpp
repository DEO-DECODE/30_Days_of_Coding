//Minimum Cost to Make at Least One Valid Path in a Grid(LeetCode).
#include <bits/stdc++.h>
using namespace std;
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
const int inf = 1e9;
int minCost(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0)), costToReach(m, vector<int>(n, inf));
    set<pair<int, pair<int, int>>> pq;
    pq.insert({0, {0, 0}});
    costToReach[0][0] = 0;
    while (pq.size() > 0)
    {
        auto pr = (*pq.begin());
        pq.erase(pq.begin());
        int cost = pr.first, x = pr.second.first, y = pr.second.second;
        if (vis[x][y])
            continue;
        vis[x][y] = 1;
        if (x == m - 1 && y == n - 1)
            return cost;
        for (int i = 1; i <= 4; ++i)
        {
            int nx = dx[i] + x, ny = dy[i] + y;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny])
            {
                int newCost = cost + (i == grid[x][y] - 1 ? 0 : 1);
                if (newCost < costToReach[nx][ny])
                {
                    pq.insert({newCost, {nx, ny}});
                    costToReach[nx][ny] = newCost;
                }
            }
        }
    }
    return -1;
}
int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}};
    cout << minCost(grid) << endl;
}
