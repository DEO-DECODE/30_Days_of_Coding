//Hamiltonian Path(GFG)
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool isHamiltonian=false;
    void dfs(int vertex, vector<int> adj[], vector<int> &vis, int &count, int N){
        vis[vertex]=1;
        count++;
        if(count==N){
            isHamiltonian=true;
            return;
        }
        for(auto child: adj[vertex]){
            if(vis[child]) continue;
            dfs(child, adj, vis, count, N);
        }
        vis[vertex]=0;
        count--;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        isHamiltonian=false;
        vector<int> adj[N+1];
        vector<int> vis(N+1,0);
        for(int i=0; i<Edges.size(); ++i){
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        for(int i=1; i<=N; ++i){
            int count=0;
            dfs(i,adj,vis,count,N);
            if(isHamiltonian){
                return true;
            }
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends
