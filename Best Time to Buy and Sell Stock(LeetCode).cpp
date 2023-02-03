#include <bits/stdc++.h>
using namespace std;
// Best Time to Buy and Sell Stock(LeetCode)
int maxProfit(vector<int> &prices)
{
    // The idea is to find the minimum price before the current day and checking profit on every day.
    int buy = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i)
    {
        profit = max(profit, prices[i] - buy);
        buy = min(buy, prices[i]);
    }
    return profit;
}
