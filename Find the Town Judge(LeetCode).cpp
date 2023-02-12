//Find the Town Judge(LeetCode).
#include <bits/stdc++.h>
using namespace std;
int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> indeg(n+1,0), outdeg(n+1,0);
    for(auto vec: trust){
        indeg[vec[1]]++; outdeg[vec[0]]++;
    }
    for(int i=1; i<=n; ++i){
        if(indeg[i]==n&&outdeg[i]==0) return i;
    }
    return -1;
}
