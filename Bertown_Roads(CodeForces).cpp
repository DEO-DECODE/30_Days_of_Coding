//Bertown Roads CODEFORCES
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int> adj[N+1];
int in[N+1],low[N+1],vis[N+1], timer;
bool hasbridge;
vector<pair<int, int>> edgelist;
void dfs(int node, int par){
    vis[node]=1;
    in[node]=low[node]=timer++;
    for(int child: adj[node]){
        if(child==par) continue;
        if(vis[child]==1){
            low[node]=min(low[node],in[child]);//lowtime will be used to identify bridge.
            //intime will be used to identify ancestor and descendent
            if(in[child]<in[node]){
                edgelist.push_back({node,child});
            }
        }
        else{
            dfs(child, node);
            if(low[child]>in[node]) {
                hasbridge=true;
                return;
            } 
            edgelist.push_back({node, child});
            low[node]=min(low[node], low[child]);

        }
    }
}
int main(){
    int n,m,a,b;
    cin>>n>>m;
    while(m--)
    cin>>a>>b, adj[a].push_back(b), adj[b].push_back(a);
    dfs(3,-1);
    if(hasbridge) cout<<0;
    else{
        for(auto pr: edgelist)
        cout<<pr.first<<" -> "<<pr.second<<endl;
    }
}
