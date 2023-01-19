#include <bits/stdc++.h>
using namespace std;
//
int main(){
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        vector<int> patients;
        multimap<int, int> mp;
        for(int i=0; i<n; ++i){
            int x;
            cin>>x;
            patients.push_back(x);
            mp.insert({x, i});
        }
        sort(patients.rbegin(), patients.rend());
        // reverse(patients.begin(), patients.end());
        int cnt=1;
        vector<int> ans(n);
        for(int i=0; i<n; ++i){
            auto itr=mp.find(patients[i]);
            int indexToInsert=(*itr).second;
            mp.erase(itr);
            ans[indexToInsert]=cnt;
            cnt++;
        }
        for(int i=0; i<n; ++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
}
