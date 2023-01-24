//Longest K unique characters substring(GFG)
#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char, int> mp;
        int cnt=0;
        int j=0;
        int ans=0;
        for(int i=0; i<s.size();++i){
            mp[s[i]]++;
            while (mp.size()>k&&j<i)
            {
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    mp.erase(mp.find(s[j]));
                }
                j++;
            }
            if(mp.size()==k){
                ans=max(ans, i-j+1);
            }
        }
        return ans==0?-1:ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
