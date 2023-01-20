#include <bits/stdc++.h>
using namespace std;
// JO V CORDINATE AGAR 0 VALUE KO CALL KR RHI MEANS WO LENGTH ME CONTRIBUTE HOGA AND OUT OF BOUND V KYUNKI BAHAR V PAANI HAI.
class Solution {
public:
    int count  = 0;
    void dfs(vector<vector<int>>&grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0 ){
           count++;
          return;
        }
        if(grid[i][j] == -1)return;
        
        grid[i][j] = -1;
        
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
         count = 0;
        for(int i = 0 ;i<grid.size() ;i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                     dfs(grid,i,j);
                     break;
                }
            }
        }
       return count; 
    }
};
