// Number of Ways to Arrive at Destination(LeetCode).
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int countPaths(int n, vector<vector<int>> &roads)
{
    vector<vector<pair<int, int>>> graph(n);
    for (auto &road : roads)
    {
        graph[road[0]].push_back({road[1], road[2]});
        graph[road[1]].push_back({road[0], road[2]});
    }

    vector<long long> dist(n, 1e12);
    vector<int> path(n, 0);

    set<pair<long long, long long>> pq;
    pq.insert({0, 0});
    dist[0] = 0;
    path[0] = 1;

    while (pq.size() > 0)
    {
        auto pr = (*pq.begin());
        pq.erase(pq.begin());

        for (auto &childPair : graph[pr.second])
        {
            long long childV = childPair.first;
            long long wt = childPair.second;

            if (dist[childV] > dist[pr.second] + wt)
            {
                dist[childV] = dist[pr.second] + wt;
                pq.insert({dist[childV], childV});
                path[childV] = path[pr.second] % mod;
            }
            else if (dist[childV] == pr.first + wt)
            {
                path[childV] += path[pr.second];
                path[childV] %= mod;
            }
        }
    }

    return path[n - 1];
}
