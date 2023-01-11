#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
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
    a = Find(a);
    b = Find(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
            swap(a, b);
        Size[a] += Size[b];
        Parent[b] = a;
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
    for(int i=0; i<n; ++i) make(i);
    for(int i=0; i<n; ++i){
        for(int j=0; j<isConnected[i].size();++j){
            if(isConnected[i][j]==1){
                Union(i,j);
            }
        }
    }
    int connected_components=0;
    for(int i=0; i<n; ++i){
        if(Find(i)==i) connected_components++;
    }
    return connected_components;
}
