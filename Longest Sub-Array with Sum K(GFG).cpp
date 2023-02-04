// Longest Sub-Array with Sum K(GFG)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int k)
    {
        unordered_map<int, vector<int>> mp;
        vector<int> temp = {-1};
        mp[0] = temp;
        int ans = 0;
        int sm = 0;
        for (int i = 0; i < N; ++i)
        {
            sm += A[i];
            if (mp.find(sm - k) != mp.end())
            {
                auto vec=mp[sm-k];
                ans = max(ans, i - vec[0]);
            }
            mp[sm].push_back(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    // code

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.lenOfLongSubarr(a, n, k) << endl;
    }

    return 0;
}
// } Driver Code Ends
