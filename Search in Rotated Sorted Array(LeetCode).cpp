// Search in Rotated Sorted Array(LeetCode)
#include <bits/stdc++.h>
using namespace std;
/*
The basic observation is that even after rotation, the entire can be divided into two sorted subarrays, So at any point(index where mid is pointing) either the left part is sorted or the right part is sorted.
So we can easily check whether the element is lying in that range or not.
*/
int search(vector<int> &nums, int target)
{
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[lo] <= nums[mid])
        {
            // left part is sorted
            if (target >= nums[lo] && target <= nums[mid])
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        else
        {
            // right part is sorted
            if (target >= nums[mid] && target <= nums[hi])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
    }
    return -1;
}
