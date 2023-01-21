//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Word Search(GFG)
class Solution
{
public:
    bool isword = false;
    void dfs(int row, int col, vector<vector<char>> &board, int index, string &word)
    {
        if (index == word.size())
        {
            isword = true;
            return;
        }
        int m = board.size(), n = board[0].size();
        if (row >= m || row < 0 || col >= n || col < 0)
            return; // out of bound check
        if (board[row][col] != word[index] || board[row][col] == '1')
            return;
        char temp = board[row][col];
        board[row][col] = '1';
        dfs(row - 1, col, board, index + 1, word);
        dfs(row + 1, col, board, index + 1, word);
        dfs(row, col - 1, board, index + 1, word);
        dfs(row, col + 1, board, index + 1, word);
        board[row][col] = temp;
    }
    bool isWordExist(vector<vector<char>> &board, string word)
    {
        isword = false;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    dfs(i, j, board, 0, word);
                }
                if (isword)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> board(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> board[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(board, word);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
