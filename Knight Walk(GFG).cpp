// Knight Walk(GFG)//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
const int dx[8] = {-1, 1, -1, 1, 2, 2, -2, -2};
const int dy[8] = {2, 2, -2, -2, -1, 1, -1, 1};
class Solution
{
public:
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        queue<pair<int, int>> q;
        pair<int, int> target = {TargetPos[0], TargetPos[1]};
        q.push({KnightPos[0], KnightPos[1]});
        vector<vector<int>> vis(N + 1, vector<int>(N + 1, 0));
        int steps = 0;
        while (q.size() > 0)
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                auto pr = q.front();
                q.pop();
                if (pr == target)
                    return steps;
                for (int mv = 0; mv < 8; ++mv)
                {
                    int childx = pr.first + dx[mv];
                    int childy = pr.second + dy[mv];
                    if (childx > N || childy > N || childx < 0 || childy < 0)
                        continue;
                    if (vis[childx][childy])
                        continue;
                    q.push({childx, childy});
                    vis[childx][childy] = 1;
                }
            }
            steps++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
