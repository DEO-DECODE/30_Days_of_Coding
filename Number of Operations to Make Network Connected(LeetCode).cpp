// Number of Operations to Make Network Connected(LeetCode).
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int Size[N], Parent[N];
void make(int v)
{
    Size[v] = 1;
    Parent[v] = v;
}
int Find(int v)
{
    if (Parent[v] == v)
        return v;
    return Parent[v] = Find(Parent[v]);
}
void Union(int a, int b)
{
    a = Find(a), b = Find(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
        {
            swap(a, b);
        }
        Size[a] += Size[b];
        Parent[b] = a;
    }
}
int makeConnected(int n, vector<vector<int>> &connections)
{
    for (int i = 0; i < n; ++i)
        make(i);
    int cnt = 0;
    int c = connections.size();
    if (n - 1 > c)
        return -1;
    for (auto vec : connections)
    {
        int u = vec[0], v = vec[1];
        if (Find(u) == Find(v))
            cnt++;
        else
        {
            Union(u, v);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (Parent[i] == i)
            ans++;

    return ans - 1;
}
