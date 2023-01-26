// Keys and Rooms(LeetCode)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
void dfs(int vertex, vector<int> &vis, int &numRooms, vector<vector<int>> &adj)
{
    vis[vertex] = 1;
    numRooms++;
    // cout << vertex << " ";
    for (auto nextRooms : adj[vertex])
    {
        if (vis[nextRooms])
        {
            continue;
        }
        dfs(nextRooms, vis, numRooms, adj);
    }
}
bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    vector<int> vis(n, 0);
    int numRooms = 0;
    dfs(0, vis, numRooms, rooms);
    if (numRooms == n)
    {
        return true;
    }

    return false;
}
int main()
{
    vector<vector<int>> rooms = {{1}, {}, {0, 3}, {1}};
    cout << canVisitAllRooms(rooms);
}
