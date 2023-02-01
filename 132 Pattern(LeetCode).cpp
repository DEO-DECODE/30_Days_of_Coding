#include <bits/stdc++.h>
using namespace std;
// 132 Pattern(LeetCode)
/*
Here minm[j] will be denoting the Ith part, Element present in the stack will be denoting the Kth part and the nums[j] will be the jth element.
Here we are doing three things:

1)Running J from n-1 to 0 , it is quite intutive as well since we have to take care of the kth part, traversing from back will help and the stack will be mantained simultaneously as well.
2)Running while loop with condition that only those element will be present at the top of stack which are greater than minimum till this index.
3)After second condition there can be only two possiblities, either the element present at the top of stack is greater than the current minimum or The stack is empty. If the stack is not empty , then we will simply check whether the element present is smaller than current element, IF yes, then we will return true.
*/
bool find132pattern(vector<int> &nums)
{
	stack<int> st;
	int n = nums.size();
	int numsk = INT_MIN;
	vector<int> minm(n, 0);
	minm[0] = nums[0];
	for (int i = 1; i < n; ++i)
	{
		minm[i] = min(nums[i], minm[i - 1]);
	}
	for (int i = n - 1; i >= 0; --i)
	{
		while (!st.empty() && st.top() <= minm[i])
		{
			// numsk = st.top();
			st.pop();
		}
		if(!st.empty()&&nums[i]>st.top()){
			return true;
		}
		st.push(nums[i]);
	}
	return false;
}
int main()
{
	vector<int> nums = {1, 0, 1, -4, -3};
	cout << find132pattern(nums);
}
