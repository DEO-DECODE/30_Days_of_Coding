// Minimum Operations (GFG)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int operationsToreach0(int ind, vector<int> &dp, int n)
    {
        if (ind < 0)
            return 1e8;
        if (ind == 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        // operation 1
        int op1=1e9;
        if(ind%2==0)
        op1 = 1 + operationsToreach0(ind/2, dp, n);
        int op2 = 1 + operationsToreach0(ind - 1, dp, n);
        return dp[ind] = min(op1, op2);
    }
    int minOperation(int n)
    {
        vector<int> dp(n+1, -1);
        return operationsToreach0(n, dp, n);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperation(n) << endl;
    }
}
// } Driver Code Ends
