//Find All Possible Recipes from Given Supplies(LeetCode).
#include <bits/stdc++.h>
using namespace std;
vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
{
    unordered_map<string, vector<string>> recipeReq;
    unordered_map<string, int> indeg;
    for (int i = 0; i < ingredients.size(); ++i)
    {
        auto item = recipes[i];
        for (auto ingrd : ingredients[i])
        {
            recipeReq[ingrd].push_back(item);
            indeg[item]++;
        }
    }
    queue<string> q;
    for (auto supply : supplies)
    {
        q.push(supply);
    }
    vector<string> ans;
    while (q.size() > 0)
    {
        auto currAvailableMaal = q.front();
        q.pop();
        auto itr = find(recipes.begin(), recipes.end(), currAvailableMaal);
        if (itr != recipes.end())
            ans.push_back((*itr));
        for (auto ingrd : recipeReq[currAvailableMaal])
        {
            indeg[ingrd]--;
            if (indeg[ingrd] == 0)
                q.push(ingrd);
        }
    }
    return ans;
}
