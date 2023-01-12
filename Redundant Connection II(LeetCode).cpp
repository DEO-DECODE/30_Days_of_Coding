#include <bits/stdc++.h>
using namespace std;
const int N = 1e5; // 9:05
int parent[N];
int Size[N];
void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
}
int find(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return parent[v] = find(parent[v]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        Size[a] += Size[b];
    }
}

vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
{
    vector<int> res;
    for (int i = 1; i <= edges.size(); ++i)
    {
        make(i);
    }
    vector<int> indegree(edges.size() + 1, -1);
    int potential_ans1 = -1;
    int potential_ans2 = -1;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        if (indegree[v] == -1)
            indegree[v] = i;
        else
        {
            potential_ans1 = i;
            potential_ans2 = indegree[v];
            break;
        }
    }

    bool flag = false;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        if (i == potential_ans1)
            continue;
        if (find(u) == find(v))
        {
            flag = true;
        }
        else
        {
            Union(u, v);
        }
        if (flag) // cycle present
        {
            if (potential_ans1 == -1) // case 2 i.e  root in cycle
                return edges[i];
            else
                return edges[potential_ans2]; // case 3 i.e non root cycle
        }
    }
    return edges[potential_ans1]; // case 1 i.e two parents without cycle
}
