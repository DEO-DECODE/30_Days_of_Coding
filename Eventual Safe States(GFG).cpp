#include <bits/stdc++.h>
using namespace std;

//Eventual Safe States(GFG)

class Solution
{
private:
    bool dfsCheck(int node, vector<int> adj[], int vis[],
                  int pathVis[],
                  int check[])
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        // traverse for adjacent nodes
        for (auto it : adj[node])
        {
            // when the node is not visited
            if (!vis[it])
            {
                if (dfsCheck(it, adj, vis, pathVis, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            // if the node has been previously visited
            // but it has to be visited on the same path
            else if (pathVis[it])
            {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        vector<int> safeNodes;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsCheck(i, adj, vis, pathVis, check);
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};

int main()
{

    // V = 12;
    vector<int> adj[12] = {{1}, {2}, {3}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, {8}, {9}};
    int V = 12;
    Solution obj;
    vector<int> safeNodes = obj.eventualSafeNodes(V, adj);

    for (auto node : safeNodes)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
