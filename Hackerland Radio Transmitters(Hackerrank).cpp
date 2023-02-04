#include <bits/stdc++.h>
using namespace std;
//Hackerland Radio Transmitters(Hackerrank)
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> houses(n);
    for(int i=0; i<n; ++i){
        cin>>houses[i];
    }
    sort(houses.begin(), houses.end());
    int cnt=0,i=0;
    while (i<n)
    {
        int nextStop=houses[i]+k;
        while (i<n&&houses[i]<=nextStop)
        {
            // Ye wala while loop ek baar extra chal rha hai.
            i++;
        }
        i--;
        cnt++;
        int nextStop2=houses[i]+k;
        while (i<n&&houses[i]<=nextStop2)
        {
            i++;
        }
        i--;
        i++;
        
    }
    cout<<cnt<<endl;
}
