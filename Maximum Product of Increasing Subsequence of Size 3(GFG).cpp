//Maximum Product of Increasing Subsequence of Size 3(GFG)
#include<bits/stdc++.h> 
using namespace std; 
class Solution{
  public:
    vector<int> maxProductSubsequence(int *arr , int n) 
    { 
        // Complete the function
        vector<int> ans = {-1, -1, -1};
        vector<int> maxTrackInRight(n, 0);
        maxTrackInRight[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            maxTrackInRight[i] = max(arr[i], maxTrackInRight[i + 1]);
        }
        set<int> st;
        for (int i = 0; i < n-1; ++i)
        {
            st.insert(arr[i]);
            auto it = st.lower_bound(arr[i]);
            if (it != st.begin() && it != st.end() && arr[i] < maxTrackInRight[i + 1])
            {
                it--;
                long long curr=(*it)*1ll*(arr[i])*maxTrackInRight[i+1];
                long long prev=(ans[0])*1ll*(ans[1])*ans[2];
                if(prev<curr){
                    ans={(*it), arr[i], maxTrackInRight[i+1]};
                }
            }
        }
        return ans;
    } 

};

//{ Driver Code Starts.
// Driver Program 
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; ++i)
	        cin>>arr[i];
	    
	    vector<int> res;
	    Solution obj;
	    res = obj.maxProductSubsequence(arr, num);
	    
	    if(res[0] == -1)
	        cout<<"Not Present\n";
	    else{
    	    for(int i = 0; i<3; ++i)
    	        cout<<res[i]<<" ";
    	    cout<<"\n";
	    }
	    
	}
} 

// } Driver Code Ends
