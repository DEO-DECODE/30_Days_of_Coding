#include <bits/stdc++.h>
using namespace std;
// Contains Duplicate III(LeetCode)
bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
{
    set<long long> st;
    for (int i = 0; i < nums.size(); ++i)
    {
        auto it = st.lower_bound(nums[i]);
        if (it != st.end())
        {
            if (((*it) - nums[i]) <= valueDiff)
                return true;
        }
        auto it2 = st.lower_bound(nums[i] - valueDiff);
        if (it2 != st.end())
        {
            if (abs((*it2) - nums[i]) <= valueDiff)
                return true;
        }
        st.insert((long long)nums[i]);
        if (i >= indexDiff)
        {
            st.erase(st.find(nums[i - indexDiff]));
        }
    }
    return false;
}
