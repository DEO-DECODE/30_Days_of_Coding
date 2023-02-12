//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// IPL 2021 - Match Day 2(gfg)
class Solution
{
public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        vector<int> ans;
        set<pair<int, int>> st;

        for (int i = 0; i < k; i++)

        {
            st.insert({arr[i], i});
        }

        ans.push_back((*--st.end()).first);

        for (int i = k; i < n; i++)

        {

            st.insert({arr[i], i});

            while ((*--st.end()).second < i - k + 1)
                st.erase(--st.end());
            // Here i-k+1 is start of the window.
            ans.push_back((*--st.end()).first);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends
