//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// Maximum difference of zeros and ones in binary string(GFG)
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int num_zeroes=0;
        int maxDiff=-1;
        int n=S.size();
        for(int i=0; i<n; ++i){
            if(S[i]=='0'){
                num_zeroes++;
            }
            else{
                num_zeroes--;
            }
            maxDiff=max(num_zeroes,maxDiff);
            if(num_zeroes<0) num_zeroes=0;
        }
        return maxDiff;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends
