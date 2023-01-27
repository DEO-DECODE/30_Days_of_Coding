#include<bits/stdc++.h>
using namespace std;
//DISTANCE OF NEAREST CELL HAVING 1 (GFG)
 // } Driver Code Ends
class Solution 
{
    public:
     int dx[4]={1,-1,0,0};
     int dy[4]={0,0,1,-1};
    //Function to find distance of nearest 1 in the grid for each cell
    // bool isvalid(vector<vector<int>> grid, int x, int y){
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     return x>=0&&y>=0&&x<m&&y<n;
    // }
    vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    queue<pair<int , int>> q;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dis(m,vector<int>(n,-1));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]==1){
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto pr=q.front();
            int cvx=pr.first;
            int cvy=pr.second;
            q.pop();
            for(int i=0; i<4; ++i){
                int childx=cvx+dx[i];
                int childy=cvy+dy[i];
                if(!(childx>=0&&childx<m&&childy>=0&&childy<n)) continue;
                if(dis[childx][childy]!=-1) continue;
                dis[childx][childy]=dis[cvx][cvy]+1;
                q.push({childx, childy});
            }
        }
        return dis;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
