//{ Driver Code Starts
#include<bits/stdc++.h>
// Strongly Connected Components (Kosaraju's Algo)(GFG)
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    vector<int> order;
    void dfs(int vertex, vector<int> &vis, vector<int> adj[])
    {
        vis[vertex] = 1;
        for (auto child : adj[vertex])
        {
            if (vis[child])
                continue;
            dfs(child, vis, adj);
        }
        order.push_back(vertex);
    }
    void rdfs(int vertex, vector<int> &vis1, vector<int> rev[])
    {
        vis1[vertex] = 1;
        for (auto child : rev[vertex])
        {
            if (vis1[child])
                continue;
            dfs(child, vis1, rev);
        }
    }
    int kosaraju(int V, vector<int> adj[])
    {
        order.clear();
        vector<int> rev[V];
        for (int i = 0; i < V; ++i)
        {
            for (auto child : adj[i])
            {
                rev[child].push_back(i);
            }
        }
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj);
            }
        }
        vector<int> vis1(V, 0);
        int cnt = 0;
        for (int i = V - 1; i >= 0; --i)
        {
            if (vis1[order[i]] == 0)
            {
                rdfs(order[i], vis1, rev);
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
