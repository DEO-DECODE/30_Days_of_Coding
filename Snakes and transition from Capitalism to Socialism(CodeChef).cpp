#include<bits/stdc++.h>
using namespace std;
//Snakes and transition from Capitalism to Socialism(CodeChef)
int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};
bool isvalid(int x, int y, int n, int m){
return x>=0&&x<n&&y>=0&&y<m;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> vec(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        
         int mx=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
            cin>>vec[i][j];
            mx=max(mx,vec[i][j]);
            }
        }
        queue<pair<int, int>> q;
        vector<vector<int>> dis(n,vector<int>(m,0));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
            if(vec[i][j]==mx){
                q.push({i,j});
                dis[i][j]=0;
                vis[i][j]=1;
            }
            }
        }
        int ans=0;
        while (!q.empty())
        {
            auto node=q.front();
            int X=node.first;
            int Y=node.second;
            q.pop();
            for(int i=0; i<8; ++i){
                int xx=X+dx[i];
                int yy=Y+dy[i];
                if(!isvalid(xx,yy,n,m)) continue;
                if(vis[xx][yy]) continue;
                dis[xx][yy]=dis[X][Y]+1;
                q.push({xx,yy});
                vis[xx][yy]=1;
                ans=max(ans, dis[xx][yy]);
            }
        }
        
        cout<<ans<<endl;
    }
}
