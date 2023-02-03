#include <bits/stdc++.h>
using namespace std;
// Spiral matrix (LeetCode)
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    /*
    There are four probable directions in sequence.
    1)East To west.
    2)Top to Down.
    3)Right to left.
    4)Down to top
    */
    int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
    int direction = 1;
    vector<int> v;
    while (top <= bottom && left <= right)
    {
        if (direction == 1)
        {
            for (int i = left; i <= right; i++)
                v.push_back(matrix[top][i]);
            direction = 2;
            top++;
        }

        else if (direction == 2)
        {
            for (int i = top; i <= bottom; i++)
                v.push_back(matrix[i][right]);
            direction = 3;
            right--;
        }

        else if (direction == 3)
        {
            for (int i = right; i >= left; i--)
                v.push_back(matrix[bottom][i]);
            direction = 4;
            bottom--;
        }

        else if (direction == 4)
        {
            for (int i = bottom; i >= top; i--)
                v.push_back(matrix[i][left]);
            direction = 1;
            left++;
        }
    }
    return v;
}
