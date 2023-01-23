#include <bits/stdc++.h>
using namespace std;
//Water Connection Problem(GFG)
class Solution
{
public:
    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        vector<vector<int>> ans;
        vector<int> vis(n + 1, 0), indeg(n + 1, 0), outdeg(n + 1, 0);
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < p; ++i)
        {
            outdeg[a[i]]++;
            indeg[b[i]]++;
            adj[a[i]].push_back({b[i], d[i]});
        }
        for(int i=1; i<=n; ++i){
            if(outdeg[i]==1&&indeg[i]==0&&vis[i]==0){
                int wt=1e9;
                int last;
                dfs(i,adj,wt,last,vis);
                ans.push_back({i,last,wt});
            }
        }
        return ans;
    }
    void dfs(int vertex, vector<pair<int, int>> adj[], int &wt, int &last, vector<int> &vis){
        vis[vertex]=1;
        for(auto child: adj[vertex]){
            if(vis[child.first]==0){
                wt=min(wt, child.second);
                last=child.first;
                dfs(child.first,adj,wt,last,vis);
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t, n, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        vector<int> a(p), b(p), d(p);
        for (int i = 0; i < p; i++)
        {
            cin >> a[i] >> b[i] >> d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n, p, a, b, d);
        cout << answer.size() << endl;
        for (auto i : answer)
        {
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
