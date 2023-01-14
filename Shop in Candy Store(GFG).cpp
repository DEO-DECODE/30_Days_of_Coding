#include <bits/stdc++.h>
using namespace std;
// Shop in Candy Store(GFG)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        // Write Your Code here
        sort(candies, candies + n);
        int j = n - 1;
        int i = 0;
        int minm = 0, mxm = 0;
        while (i <= j)
        {
            minm += candies[i];
            i++;
            j = j - k;
        }
        sort(candies, candies + n, greater<int>());
        i = 0, j = n - 1;

        while (i <= j)
        {
            mxm += candies[i];
            i++;
            j=j-k;
        }

        return {minm, mxm};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
