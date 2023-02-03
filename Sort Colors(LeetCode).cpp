#include <bits/stdc++.h>
using namespace std;
//
void sortColors(vector<int>& nums) {
        /*
    The algorithm is based on the fact that all the elements to the left of lo is 0s and all the elements to the
    right of hi is 2.
    */
    
    int lo = 0, hi = nums.size() - 1, mid = 0;
    while (mid <= hi)
    {
        if (nums[mid] == 0)
        {
            swap(nums[lo], nums[mid]);
            lo++, mid++;
        }
        else if (nums[mid] == 1)
            mid++;
        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[hi]);
            hi--;
        }
    }
    }
