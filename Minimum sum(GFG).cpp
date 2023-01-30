// Minimum sum(GFG)
#include <bits/stdc++.h>
using namespace std;
// We have to form two numbers using the elements of the array .	i	n order to have minimum sum the length of the two nubers should be almost same.
class Solution{   
public:
    string solve(int arr[], int n) {
        sort(arr, arr+n);
		long long num1=0, num2=0;
		int ind=0;
		while (ind<n)
		{
			num1=num1*10+arr[ind++];
			if(ind<n)
			num2=num2*10+arr[ind++];
		}

		return to_string(num1+num2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
