#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        if(n==1) return 0;
        multiset<long long > pq;
        for (int i = 0; i < n; ++i)
        {
            pq.insert(arr[i]);
        }
        long long cost = 0;
        while (pq.size() > 1)
        {
            // cout<<1;
            auto fst = pq.begin(), scnd = ++pq.begin();
            cost += (*fst) + (*scnd);
            // cout<<(*fst)<<" "<<(*scnd)<<endl;
            pq.insert((*fst) + (*scnd));
            pq.erase(fst);
            pq.erase(scnd);
        }
        // cout<<endl;
        return cost;
    }
};
