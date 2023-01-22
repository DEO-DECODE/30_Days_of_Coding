//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossible(int arr[], int n, int k, long long mid)
    {
        int count = 1;

        int sum = 0;

        for (int i = 0; i < n; i++)
        {

            if (sum + arr[i] <= mid)
            {

                sum += arr[i];
            }
            else
            {

                count++;

                if (count > k || arr[i] > mid)
                {

                    return false;
                }
                else
                {

                    sum = arr[i];
                }
            }
        }

        return true;
    }

    long long minTime(int arr[], int n, int k)
    {
         long long sum=0;

        long long lo=*max_element(arr,arr+n);

        long long  hi=accumulate(arr,arr+n,sum);

        long long ans=-1;
        while (lo<=hi)
        {
            long long mid = (hi + lo) / 2;
            // cout << mid << endl;
            if (isPossible(arr, n, k, mid))
            {
                ans = mid;
                hi = mid-1;
            }
            else
            {
                lo = mid + 1;
            }
            // cout << lo << " " << hi << endl;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends
