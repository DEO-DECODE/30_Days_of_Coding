#include <bits/stdc++.h>
using namespace std;
//Find most competitive subsequence (LeetCode)
/*
So you can't think of Priority queue as the question has asked for subsequence , therefore order matters as well :| So, The data strucure which can keep track of the previous inputs as well as mantain the order is Stack.
At every iteration We will check whether the current number has the potential to pop the element present at the top of the top , If it has we will keep popping element but We have to take care of one thing
taht , do we have enough elements after the present element, if we have then we can, otherwise, we can't
Condition:
while (!lexicoSmaller.empty()&&nums[i]<lexicoSmaller.top()&&(n-i-1)>=k-lexicoSmaller.size())
Here (n-i-1) represents that how much element do we have ahead and
(K- lexicoSmaller.size()) represents, how much more elment do we need to mantain the stack of size k.
*/
vector<int> mostCompetitive(vector<int>& nums, int k) {
    int n=nums.size();
    stack<int> st;
    for(int i=0; i<n; ++i)
    {
        while(!st.empty()&&nums[i]<st.top()&&(n-i-1)>=k-st.size())
        st.pop();
        if(st.size()<k){
            st.push(nums[i]);
        }
    }
    vector<int> ans(k);
    while(!st.empty()){
        ans[--k]=st.top();
        st.pop();
    }
    return ans;
}
