// Check if it is possible to survive on Island(GFG)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        int numSundays = S / 7;
        int totalFoodReq=S*M;
        int buyingDays=totalFoodReq/N;
        if(totalFoodReq%N!=0){
            buyingDays++;
        }
        if(buyingDays<=S-numSundays){
            return buyingDays;
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int S, N, M;
        cin >> S >> N >> M;

        Solution ob;
        cout << ob.minimumDays(S, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends
