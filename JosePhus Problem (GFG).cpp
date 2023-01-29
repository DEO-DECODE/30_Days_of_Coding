//JosePhus Problem (GFG)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int ans;
    int recursion(int n, int k){
    // cout<<"\n"<<nxt<<" "<<sze<<" "<<swrd<<endl;
    if(n==1) return 0;
    int x= recursion(n-1,k);
    int y=(x+k)%n;
    return y;
}
    int josephus(int n, int k)
    {
       //Your code here
      ans =recursion(n,k);
      return ans+1;
    }
};



// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends
