#include<bits/stdc++.h> 
using namespace std; 
// Maximum Subarray(leetCode)
/*
Intuition
Since we are not told to find a subarray of given fixed length , therefore sliding window will not help :( . That's why we have to use Kadan's algorithm.

Approach
If all the elements in the array is positive then we will simply return the sum of all the elements in the array.
Otherwise we will simply use Kadan's algo.
[1,-2] -> 1
[1, -2, 1] -> 1
[1, -2, 2] ->2
[4, -2, 3] ->5
The basic idea behing Kadan's algorithm is that we will exclude that part , that is resulting our ongoing sum as negative as it will surely decrease our ans.
[4,3,7,-12,-6,5,8,-1,12]
Before index 3 the sm was 14 so it can be a potential answer , moving on we see -12 at ind 3 it results our sum to 2 but still we will not recompute sum as there may be some higher positive number later on. but once we reach at index 4 it will make the sum as -4 so, There may be some higher positive number later on but this part will simply decrease the overall answer therefore we will start computing again from next index by updating sm=0.
*/
int maxSubArray(vector<int> &arr)
{
    long long maxSum = INT_MIN;
    long long sm = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        sm += arr[i];
        maxSum = max(maxSum, sm);
        if (sm < 0)
            sm = 0;
    }
    return maxSum;
}
