#include <bits/stdc++.h>
using namespace std;
// Find K Closest Elements
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> ans;
    int n = arr.size();
    int lo=0, hi=n-1;
    while (hi-lo>=k)
    {
        if(abs(arr[lo]-x)>abs(arr[hi]-x)){
            lo++;
        }
        else{
            hi--;
        }
    }
    for(int i=lo; i<=hi; ++i){
        ans.push_back(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    auto ans = findClosestElements(arr, 4, 3);
}
