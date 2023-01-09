#include <bits/stdc++.h>
using namespace std;
// Gas Tank(LEEtCode)
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    if (accumulate(gas.begin(), gas.end(), 0) - accumulate(cost.begin(), cost.end(), 0) < 0)
        return -1;
    int n = gas.size();
    int ans = 0, stock = 0;
    for (int i = 0; i < n; ++i)
    {
        stock += gas[i];
        stock -= cost[i];
        if (stock < 0)
        {
            ans = i + 1;
            stock = 0;
        }
    }
    return ans;
}
int main()
{
    vector<int> gas = {5, 1, 2, 3, 4};
    vector<int> cost = {4, 4, 1, 5, 1};
    int x = canCompleteCircuit(gas, cost);
    cout << x << endl;
}
