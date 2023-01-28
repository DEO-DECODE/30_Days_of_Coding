// Path of greater than equal to k length(GFG)
#include <bits/stdc++.h>
using namespace std;
bool ans=false;
void dfs(vector<pair<int, int>> adj[], int k, int vertex, int &pathLength, vector<int> &vis){
    if(pathLength>=k){
        ans=true;
        return;
    }
    vis[vertex]=1;
    for(auto child: adj[vertex]){
        int cv=child.first;
        int len=child.second;
        if(vis[cv]) continue;
        pathLength=pathLength+len;
        dfs(adj,k,cv,pathLength,vis);
        pathLength=pathLength-len;
    }
    vis[vertex]=0;
}
bool pathMoreThanK(int v, int E, int k, int *a)
{
    ans=false;
    vector<int> vis(v+1, 0);
    vector<pair<int, int>> adj[v];
    for(int i=0; i<3*E-2; i+=3){
        adj[a[i]].push_back({a[i+1], a[i+2]});
        adj[a[i+1]].push_back({a[i], a[i+2]});
    }
    int pathLength=0;
    dfs(adj,k,0,pathLength, vis);
    return ans;
}
