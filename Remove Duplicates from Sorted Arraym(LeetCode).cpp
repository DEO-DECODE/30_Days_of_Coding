// Remove Duplicates from Sorted Arraym(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    int i=0, j;
    for(int j=1; j<nums.size(); ++j){
        if(nums[i]!=nums[j]){
            // Present wala number, next wale k 
            // equal nhi hai
            i++;
            nums[i]=nums[j];
        }
        // agar equal hai to hm us case mein i
        // i ko increment nhi kara rhein.
    }
    return i+1;
}
