//Friends Pairing Problem(GFG)
#include <bits/stdc++.h>
using namespace std;

/*
f(n) = ways n people can remain single 
       or pair up.

For n-th person there are two choices:
1) n-th person remains single, so only 1 way so  we recur 
   for remaining i.e f(n - 1)   or you can say 1*f(n-1)
2) n-th person pairs up with any of the 
   remaining n - 1 persons. So apart from the 2 people forming a pair for remaining n-2 persons we We get (n - 1) * f(n - 2) ways

Therefore we can recursively write f(n) as:
f(n) = f(n - 1) + (n - 1) * f(n - 2)
*/

class Solution
{
public:
    long long mod = 1e9 + 7;

    int f(int ind, vector<int> &dp)
    {
        if (ind <= 2)
            return ind;
        if (dp[ind] != -1)
            return dp[ind];
        int a = (((ind - 1) % mod) * f(ind - 2, dp) % mod) % mod;
        int b = (1 * f(ind - 1, dp)) % mod;
        return dp[ind] = a + b;
    }
    int countFriendsPairings(int n)
    {
        vector<int> dp(n + 1, -1);
        return f(n, dp) % mod;
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
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}

// } Driver Code Ends
