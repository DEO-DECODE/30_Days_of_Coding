// Greg and Graph(codeChef)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
long long dis[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> dis[i][j];
        }
    }
    vector<int> del_Order(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> del_Order[i];
    }
    reverse(del_Order.begin(), del_Order.end());
    vector<long long> ans;
    for (int k = 0; k < n; ++k)
    {
        int k_v = del_Order[k];
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                long long newDist = dis[i][k_v] + dis[k_v][j];
                dis[i][j] = min(dis[i][j], newDist);
            }
        }
        long long sum=0;
        for(int i=0; i<=k; ++i){
            for(int j=0; j<=k; ++k){
                sum+=dis[del_Order[i]][del_Order[j]];
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
}
