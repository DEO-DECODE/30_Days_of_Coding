// Find Closest Node to Given Two Nodes(LeetCode).
#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
void bfs(int node1, vector<int> &edges, vector<int> &dis)
{
    queue<int> q;
    q.push(node1);
    dis[node1] = 0;
    while (q.size() > 0)
    {
        auto currv = q.front();
        q.pop();
        auto childv = edges[currv];
        if (childv != -1 && dis[childv] == inf)
        {
            q.push(childv);
            dis[childv] = dis[currv] + 1;
        }
    }
}
int closestMeetingNode(vector<int> &edges, int node1, int node2)
{
    int n = edges.size();
    vector<int> dis1(n, inf), dis2(n, inf);
    bfs(node1, edges, dis1);
    bfs(node2, edges, dis2);
    int node=-1, maxDis = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        if (dis1[i] == inf || dis2[i] == inf)
            continue;
        if(maxDis>(dis1[i],dis2[i])){
            maxDis=max(dis1[i], dis2[i]);
            node=i;
        }
    }
    return node;
}
