#include <bits/stdc++.h>
using namespace std;
// Sliding Window Maximum(LeetCode)
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    multiset<int> st;
    for (int i = 0; i < nums.size(); ++i)
    {
        st.insert(nums[i]);
        if (i >= k - 1)
        {
            auto itr = --st.end();
            ans.push_back((*itr));
            cout<<i<<" "<<(*itr)<<endl;
            st.erase(st.find(nums[i - k + 1]));
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 3, 1, 2, 0, 5};
    int k = 3;
    auto ans = maxSlidingWindow(nums, k);
}
