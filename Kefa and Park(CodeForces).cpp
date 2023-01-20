// Kefa and Park(CodeForces)
#include <bits/stdc++.h>
using namespace std;
// Kefa and Park(CodeForces)
const int N = 1e5;
vector<int> graph[N];
vector<int> cats(N);
bool vis[N];
int ans = 0;
int n, m;
void dfs(int vertex, int count)
{
    if (cats[vertex] == 1)
        count++;
    else
        count = 0;
    // since we are told to take care of number of consecutive cats
    if (count > m)
        return;
    int numchild = 0;
    for (auto child : graph[vertex])
    {
        if (vis[child])
            continue;
        dfs(child, count);
        numchild++;
    }
    if (numchild == 0)
    {
        // It means it is a leafNode
        cout << vertex << endl;
        ans++;
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> cats[i];
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    dfs(1, 0);
    cin >> ans;
}
