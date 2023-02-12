// Detonate the Maximum Bombs(LeetCode).
#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> &graph, int vertex, int n, int &cnt)
{
    queue<int> q;
    vector<int> vis(n + 1, 0);
    q.push(vertex);
    while (q.size() > 0)
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            int x = q.front();
            q.pop();
            vis[x] = 1;
            cnt++;
            for (auto p : graph[x])
            {
                if (!vis[p])
                {
                    q.push(p);
                    vis[p] = 1;
                }
            }
        }
    }
}
int maximumDetonation(vector<vector<int>> &bombs)
{
    int n = bombs.size();
    vector<vector<int>> graph(n);
    // Creating adjacency list
    for (int i = 0; i < n; ++i)
    {
        long long x1 = bombs[i][0];
        long long y1 = bombs[i][1];
        long long r1 = bombs[i][2];
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;
            long long x2 = bombs[j][0];
            long long y2 = bombs[j][1];
            long long dist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
            if (dist <= r1 * r1)
            {
                graph[i].push_back(j);
            }
        }
    }
    int answer = 0, cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cnt = 0;
        bfs(graph, i, n, cnt);
        answer = max(answer, cnt);
    }
    return cnt;
}
