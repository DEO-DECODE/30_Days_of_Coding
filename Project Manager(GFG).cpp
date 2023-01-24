// Project Manager(GFG)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m)
    {
        queue<int> q;
        vector<int> inDeg(n, 0), timeReq(n, 0), adj[n];
        for (int i = 0; i < m; ++i)
        {
            inDeg[dependency[i].second]++;
            adj[dependency[i].first].push_back(dependency[i].second);
        }
        for(int i=0; i<n; ++i){
            if(inDeg[i]==0){
                q.push(i), timeReq[i]=duration[i];
            }
        }
        int numNodes=0;
        while (q.size()>0)
        {
            int frnt = q.front();
            q.pop();
            numNodes++;
            for(auto v: adj[frnt]){
                timeReq[v]=max(timeReq[v], timeReq[frnt]+duration[v]);
                inDeg[v]--;
                if(inDeg[v]==0) q.push(v);
            }
        }
        if(numNodes!=n) return -1;
        return (*max_element(timeReq.begin(), timeReq.end()));
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m;
        int duration[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++)
            cin >> duration[i];
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            dependency.push_back({x, y});
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends
