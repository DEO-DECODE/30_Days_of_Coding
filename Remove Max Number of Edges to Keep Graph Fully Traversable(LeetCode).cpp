// Remove Max Number of Edges to Keep Graph Fully Traversable(LeetCode).
#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] != b[0])
    {
        return a[0] > b[0];
    }
    else if (a[1] != b[1])
    {
        return a[1] > b[1];
    }
    return a[2] > b[2];
}
const int N = 1e5 + 7;
class DSU
{
public:
    int Parent[N], Size[N];
    void Make(int v)
    {
        Parent[v] = v;
        Size[v] = 1;
    }
    int Find(int v)
    {
        if (Parent[v] == v)
            return v;
        return Parent[v] = Find(Parent[v]);
    }
    bool Union(int a, int b)
    {
        a = Find(a), b = Find(b);
        if (a == b)
            return false;
        else if (a != b)
        {
            if (Size[a] < Size[b])
                swap(a, b);
            Parent[b] = a;
            Size[a] += Size[b];
        }
        return true;
    }
};
int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
{

    DSU alice, bob;
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i <= n; ++i)
    {
        alice.Make(i), bob.Make(i);
    }
    int removedEdges = 0, totalEdges = 0;

    for (auto e : edges)
    {
        if (e[0] == 3)
        {
            bool isEdgeValidForAlice = alice.Union(e[1], e[2]);
            bool isEdgeValidForBob = bob.Union(e[1], e[2]);

            if (isEdgeValidForAlice)
                totalEdges++; // made the edge
            if (isEdgeValidForBob)
                totalEdges++; // made the edge

            if (!isEdgeValidForAlice || !isEdgeValidForBob)
                removedEdges++; // remove the edge if it's not valid
        }
        else if (e[0] == 1)
        {
            bool isEdgeValidForAlice = alice.Union(e[1], e[2]);
            if (isEdgeValidForAlice)
                totalEdges++;
            else
                removedEdges++;
        }
        else
        {
            bool isEdgeValidForBob = bob.Union(e[1], e[2]);
            if (isEdgeValidForBob)
                totalEdges++;
            else
                removedEdges++;
        }
    }

    if (totalEdges != 2 * n - 2)
        return -1; // n - 1 for alice and n - 1 for bob

    return removedEdges;
}
