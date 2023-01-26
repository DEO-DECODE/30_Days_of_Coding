#include <bits/stdc++.h>
using namespace std;
//(LONELY ISLAND HACKEREARTH)
const int N = 2e5 + 7;
vector<int> adj[N];
vector<int> indeg(N);
vector<double> prob(N);
vector<double> outdeg(N);
queue<int> q;
vector<int> ans;
double eps = 1e-9;
int n, m, r;
void toposort()
{
    for (int i = 1; i <= n; ++i)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int frnt = q.front();
        q.pop();
        ans.push_back(frnt);
        for (auto nodes : adj[frnt])
        {
            indeg[nodes]--;
            prob[nodes] += prob[frnt] / outdeg[frnt];
            if (indeg[nodes] == 0)
            {
                q.push(nodes);
            }
        }
    }
}
int main()
{
    cin >> n >> m >> r;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        if (x != y)
        {
            adj[x].push_back(y);
            outdeg[x]++;
            indeg[y]++;
        }
    }
    prob[r] = 1;
    toposort();
    double mxx = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (outdeg[i] == 0)
        {
            mxx = max(mxx, prob[i]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (outdeg[i] == 0 && abs(prob[i] - mxx) <= eps)
            cout << i << " ";
    }
    return 0;
}
