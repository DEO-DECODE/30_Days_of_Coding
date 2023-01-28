// Oliver and the Game(HackerEarth)
#include <bits/stdc++.h>
using namespace std;
/*
Oliver's turn to hide and Bob is supposed to find him.Oliver can hide in any of the houses in the city including the King's Mansion. As Bob is a very lazy person, for finding Oliver, he either goes towards the King's Mansion (he stops when he reaches there), or he moves away from the Mansion in any possible path till the last house on that path.
0 X Y : Bob moves towards the King's Mansion.
1 X Y : Bob moves away from the King's Mansion
*/
/*
Oliver runs and hides in some house (say X) and Bob is starting the game from his house (say Y).
In order for x to be in the subtree of y
in[x]>in[y] and out[x]<out[y]
*/
const int N = 1e5 + 3;
vector<int> adj[N];
int in[N], out[N], vis[N];
void dfs(int source, int &counter)
{
    vis[source] = 1;
    counter++;
    in[source] = counter;
    for (auto child : adj[source])
    {
        if (vis[child])
            continue;
        dfs(child, counter);
    }
    counter++;
    out[source] = counter;
}
bool check(int x, int y)
{
    if (in[x] > in[y] && out[x] < out[y])
    {
        return true;
        // basically x, y ke subtree me present hai.
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int counter = 0;
    dfs(1, counter);
    int q;
    cin >> q;
    while (q--)
    {
        int ind, x, y;
        cin >> ind >> x >> y;
        if (!check(x, y) && (!check(y, x)))
        {
            cout << "NO\n";
            continue;
        }
        if (ind == 0)
        {
            // mtlb y ko x ke subtree me hona hoga
            if (check(y, x))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        if (ind == 1)
        {
            if (check(x, y))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}
