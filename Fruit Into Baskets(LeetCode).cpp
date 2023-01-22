// Fruit Into Baskets(LeetCode)
#include <bits/stdc++.h>
using namespace std;
/*
 */
int totalFruit(vector<int> &fruits)
{
    unordered_map<int, int> mp;
    int j = 0;
    int ans = 0;
    for (int i = 0; i < fruits.size(); ++i)
    {
        mp[fruits[i]]++;
        // bool check = false;
        while (mp.size() > 2 && j < i)
        {
            // if (!check)
            // {
            //     cout << j << " " << i << endl;
            // }
            // check = true;
            mp[fruits[j]]--;
            if (mp[fruits[j]] == 0)
            {
                mp.erase(mp.find(fruits[j]));
            }
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    return ans;
}
int main()
{
    vector<int> fruits = {1, 3, 3, 3, 1, 2, 2, 1, 2, 2, 1, 3, 1};
    cout << totalFruit(fruits);
}
