// Maximum Points You Can Obtain from Cards(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
    if (k == cardPoints.size())
        return totalSum;
    int slidingWindowLength = cardPoints.size() - k;
    int minSum = INT_MAX;
    int i = 0;
    int sm = 0;
    for (i = 0; i < slidingWindowLength; ++i)
    {
        sm += cardPoints[i];
    }
    while (i < n)
    {
        if (sm < minSum)
        {
            minSum = sm;
        }
        // Acquire
        sm += cardPoints[i];
        // Release
        sm -= cardPoints[i - slidingWindowLength];
        i++;
    }
    if (sm < minSum)
    {
        minSum=sm;
    }
    return totalSum-minSum;
}
