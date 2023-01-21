// Count the paths(GFG)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<int> adj[], int vertex, int &cnt, int d)
    {
        if (vertex == d){
            cnt++;
            return;
        }
        for (auto child : adj[vertex])
        {
            dfs(adj, child, cnt, d);
        }
    }
    int possible_paths(vector<vector<int>> edges, int n, int s, int d)
    {
        vector<int> adj[n + 1];
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }
        int cnt = 0;
        dfs(adj, s, cnt, d);
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, s, d;
        cin >> n >> m >> s >> d;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        int ans = obj.possible_paths(edges, n, s, d);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
