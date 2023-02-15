#include <bits/stdc++.h>
using namespace std;
// PivotIndex(LeetCode)
int pivotIndex(vector<int> &nums)
{
	int n=nums.size();
	vector<int> prefixSum(n,0), postfixSum(n,0);
	prefixSum[0]=nums[0];
	postfixSum[n-1]=nums[n-1];
	int st=1, en=n-2;
	int pivotIndex=-1;
	for(int i=0; i<n-1; ++i){
		prefixSum[st]=prefixSum[st-1]+nums[st];
		postfixSum[en]=postfixSum[en+1]+nums[en];
		st++;
		en--;
	}
	for(int i=1; i<n-1; ++i){
		if(prefixSum[i]==postfixSum[i]){
			pivotIndex=i;
		}
	}
	return pivotIndex;
}
