//Snake and Ladder Problem(GFG)
#include <bits/stdc++.h>
using namespace std;

int minThrow(int N, int arr[])
{
    unordered_map<int, int> ladders, snakes;
    for (int i = 0; i < 2 * N; i += 2)
    {
        if (arr[i] < arr[i + 1]) // ladder
        {
            ladders[arr[i]] = arr[i + 1];
        }
        else
        { // snakes
            snakes[arr[i]] = arr[i + 1];
        }
    }
    int moves = 0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vector<int> vis(31, 0);
    vis[1] = true;
    while (q.size() > 0 && !found)
    {
        int sz = q.size();
        for (int i = 0; i < sz; ++i)
        {
            auto curr = q.front();
            q.pop();
            for (int die = 1; die <= 6; ++die)
            {
                if (curr + die == 30)
                {
                    found = true;
                }
                else if (curr + die <= 30 && ladders[curr + die]!=0 && vis[curr + die] == 0)
                {
                    // ladder hai
                    vis[ladders[curr + die]] = 1;
                    q.push(ladders[curr + die]);
                    if (ladders[curr + die] == 30)
                    {
                        found = true;
                    }
                }
                else if (curr + die <= 30 && snakes[curr + die]!=0 && vis[curr + die] == 0)
                {
                    // snake hai
                    vis[snakes[curr + die]] = 1;
                    q.push(snakes[curr + die]);
                    if (snakes[curr + die] == 30)
                    {
                        found = true;
                    }
                }
                else if (curr + die <= 30 && ladders[curr + die] == 0 && snakes[curr + die] == 0 && vis[curr + die] == 0)
                {
                    // ladder hai
                    vis[curr + die] = 1;
                    q.push(curr + die);
                    if (curr + die== 30)
                    {
                        found = true;
                    }
                }
            }
        }
        moves++;
    }
    return moves;
}
