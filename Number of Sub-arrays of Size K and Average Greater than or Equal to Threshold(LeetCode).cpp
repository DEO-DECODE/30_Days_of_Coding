#include <bits/stdc++.h>
using namespace std;
// Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold(LeetCode)
int numOfSubarrays(vector<int> &arr, int k, int threshold)
{
    int sm = 0, i;
    for (i = 0; i < k; ++i)
    {
        sm += arr[i];
    }
    int cnt = 0;
    int value = threshold * k;
    while (i < arr.size())
    {
        if (sm >= value)
            cnt++;
        // Acquire
        sm += arr[i];
        // release
        sm -= arr[i - k];
        i++;
    }
    if(sm>=value) cnt++;
    return cnt;
}
