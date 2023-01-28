//A walk to remember(Hackerearth)
#include <bits/stdc++.h>
using namespace std;
/*
.Kosaraju's algorithm helps to find number of strongly connected components in a directed graph.
.Strongly connected component: If we can start from any node and we can reach to any other node in that component that is to the starting node as well.
.If we have cycle in a graph, then from any node of the cycle we can return back to the starting node
*/
vector<int> order;
vector<vector<int>> ans;
const int N=1e5+3;
vector<int> graph[N];
vector<int> rev[N];
vector<int> ans2(N);
/*
5 5
1 2
2 3
3 1
2 4
4 5
*/
void dfs(int src, vector<int> graph[], vector<int> &vis){
    vis[src]=1;
    // cout<<1;
    for(auto child: graph[src]){
        if(vis[child]) continue;
        dfs(child,graph,vis);
    }
    order.push_back(src);
}
void dfs2(int src, vector<int> rev[], vector<int> &vis2, vector<int> &subg){
    vis2[src]=1;
    for(auto child: rev[src]){
        if(vis2[child]) continue;
        dfs2(child,rev,vis2, subg);
    }
    subg.push_back(src);
}

int main()
{
    int n,m;
	cin>>n>>m;

	for(int i=0; i<m; ++i){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
        rev[y].push_back(x);
	}
    vector<int> vis(n+1,0);
    vector<int> vis2(n+1,0);
    for(int i=1; i<=n; ++i){
        if(vis[i]) continue;
        dfs(i,graph,vis);
    }
    // for(int i=0; i<order.size(); i++)
    // cout<<order[i]<<" ";
    // cout<<"\n\n";
    for(int v=order.size()-1; v>=0; --v){
        if(vis2[order[v]]) continue;
        vector<int> subg;
        dfs2(order[v],rev,vis2,subg);
        ans.push_back(subg);
    }
    
    for(auto vec: ans){
        if(vec.size()>1){
        for(auto val: vec)
        ans2[val]=1;
        }
        
    }
    for(int i=1; i<=n; ++i)
    cout<<ans2[i]<<" ";
}
