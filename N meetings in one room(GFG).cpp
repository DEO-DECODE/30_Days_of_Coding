//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
  static  bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; ++i)
        {
            vec[i] = {start[i], end[i]};
        }
        int prevWorking = -1;
        sort(vec.begin(), vec.end(), cmp);
        int i=0;
        int numActivity=0;
        while (i<n)
        {
            if(prevWorking<vec[i].first){
                numActivity++;
                prevWorking=vec[i].second;
            }
            i++;
        }
        return numActivity;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
