// Longest Repeating Subsequence(GFG)
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int f(int ind1, int ind2, string &A, string &B, vector<vector<int>> &dp, int n)
    {
        if (ind1 == n || ind2 == n)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        // Case of Match
        int match = 0, notMatch = 0;
        if (A[ind1] == B[ind2] && ind1 != ind2)
        {
            match = 1 + f(ind1 + 1, ind2 + 1, A, B, dp, n);
        }
        else
        {
            notMatch = max(f(ind1, ind2 + 1, A, B, dp, n), f(ind1 + 1, ind2, A, B, dp, n));
        }
        return dp[ind1][ind2] = max(match, notMatch);
    }
    int LongestRepeatingSubsequence(string str)
    {
        int n=str.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        string str2=str;
        return f(0,0,str, str2, dp, n);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
