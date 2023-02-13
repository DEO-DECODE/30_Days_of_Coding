//Pairs with specific difference(GFG)
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr, arr+N, greater<int>());
        int ans=0;
        for(int i=0; i<N-1; ++i){
            if(arr[i]-arr[i+1]<K){
                ans+=(arr[i]+arr[i+1]);
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends
