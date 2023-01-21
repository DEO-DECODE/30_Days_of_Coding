// Party in Town(GFG)
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
class Solution
{
public:
    int bfs(vector<vector<int>> &adj, int src)
    {
        vector<int> dis(adj.size() + 1, inf);
        dis[src] = 0;
        queue<int> q;
        q.push(src);
        int maxDist = INT_MIN;
        while (q.size() > 0)
        {
            int currv = q.front();
            q.pop();
            for (auto child : adj[currv])
            {
                if (dis[child] != inf)
                    continue;
                dis[child] = dis[currv] + 1;
                maxDist = max(maxDist, dis[child]);
                q.push(child);
            }
        }
        return maxDist;
    }
    int partyHouse(int N, vector<vector<int>> &adj)
    {
        int ans = INT_MAX;
        for (int i = 1; i <= N; ++i)
        {
            ans = min(ans, bfs(adj, i));
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
        int N, x, y;
        cin >> N;
        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < N - 1; i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }

        Solution ob;
        cout << ob.partyHouse(N, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends
