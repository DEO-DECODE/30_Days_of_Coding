#include <bits/stdc++.h>
using namespace std;
int ans;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool isvalid(int r, int c, vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    return r >= 0 && r < n && c >= 0 && c < m;
}
void dfs(vector<vector<int>> &matrix, int row, int col, int pathLength)
{
    ans=max(ans, pathLength);
    for (int mv = 0; mv < 4; ++mv)
    {
        int childX = row + dx[mv];
        int childY = col + dy[mv];
        int temp = matrix[row][col];
        if (!isvalid(childX, childY, matrix))
            continue;
        if (matrix[childX][childY] == -1)
            continue;
        if (matrix[childX][childY] > temp)
        {
            matrix[row][col] = -1;
            dfs(matrix, childX, childY, pathLength + 1);
            matrix[row][col] = temp;
        }
    }
}
int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int finalAns=0;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            ans = 0;
            dfs(matrix, i, j, 1);
            finalAns = max(finalAns, ans);
        }
    }
    return finalAns;
}
