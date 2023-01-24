#include <bits/stdc++.h>
using namespace std;
// Chef and Reversing (Codechef)
/*
The evening was boring and chef has nothing else to do, so to entertain himself, Chef thought about a question 
"What is the minimum number of edges he needs to reverse in order to have at least one path from vertex 1 to 
vertex N, where the vertices are numbered from 1 to N.
*/
const int N=1e5+10;
const int inf=1e9+10;
vector<pair<int, int>> g[N];
vector<int> lev(N, inf);
int n,m;
int bfs(){
    deque<int> q;
    lev[1]=0;
    q.push_front(1);
    while(!q.empty()){
        int cur_v=q.front();
        q.pop_front();
        for(auto child: g[cur_v]){
            int childv=child.first;
            int wt=child.second;
            if(lev[cur_v]+wt<lev[childv]){
                lev[childv]=lev[cur_v]+wt;
                if(wt==0){
                    q.push_front(childv);
                }
                if(wt==1){
                    q.push_back(childv);
                }
            }
        }
        
    }
    return lev[n]==inf ? -1: lev[n];
}
int main(){
    cin>>n>>m;
    for(int i=0; i<m ; ++i){
        int x,y;
        cin>>x>>y;
        if(x==y) continue;
        g[x].push_back({y,0});
        g[y].push_back({x,1});
    }
    cout<<bfs();
}
