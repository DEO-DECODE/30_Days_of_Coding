//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int nums[], int n)
    {
        // code here
        // int n = nums.size();
    sort(nums, nums+n);
    int i = 0;
    int ans = 0;
    for (int k = n - 1; k >= 2; --k)
    {
        int i = 0, j = k - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] > nums[k])
            {
                ans += j - i;
                j -= 1;
            }
            else
            {
                i += 1;
            }
        }
        i = 0;
    }
    return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}
// } Driver Code Ends
