// Maximum Erasure Value(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int maximumUniqueSubarray(vector<int> &nums)
{
    int n = nums.size();
    int j = 0, sm = 0;
    int ans = 0;
    unordered_map<int, int> freqMap;
    for (int i = 0; i < n; ++i)
    {
        sm += nums[i];
        freqMap[nums[i]]++;
        while (j < i && freqMap[nums[i]] > 1)
        {
            // cout<<i<<" "<<j<<endl;
            freqMap[nums[j]]--;
            sm -= nums[j];
            j++;
        }
        // cout<<sm<<endl;
        ans = max(ans, sm);
    }
    return ans;
}
int main(){
    vector<int> nums={10000,1,10000,1,1,1,1,1,1};
    cout<<maximumUniqueSubarray(nums);
}
