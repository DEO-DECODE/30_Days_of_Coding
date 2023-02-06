// Most Stones Removed with Same Row or Column(LeetCode).
#include <bits/stdc++.h>
using namespace std;
// DisJoint Set Union Code
const int N = 1e5 + 7;
int Size[N], Parent[N];
void make(int v)
{
    Size[v] = 1;
    Parent[v] = v;
}
int Find(int v)
{
    if (Parent[v] == v)
        return v;
    return Parent[v] = Find(Parent[v]);
}
void Union(int a, int b)
{
    a = Find(a), b = Find(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
        {
            swap(a, b);
        }
        Size[a] += Size[b];
        Parent[b] = a;
    }
}
int removeStones(vector<vector<int>> &stones)
{
    int maxRow = 0, maxCol = 0;
    for (auto vec : stones)
    {
        maxRow = max(maxRow, vec[0]);
        maxCol = max(maxCol, vec[1]);
    }
    // cout<<maxRow<<" "<<maxCol<<endl;
    for(int i=0; i<=maxRow+maxCol+1; ++i) make(i);
    vector<int> coordinates;
    for (auto vec : stones)
    {
        int nodeRow = vec[0];
        int nodeCol = vec[1] + maxRow + 1;
        Union(nodeRow, nodeCol);
        coordinates.push_back(nodeCol), coordinates.push_back(nodeRow);
    }
    int connectedComponents=0;
    // for (int i = 0; i <= maxRow+maxCol+1; ++i)
    // {
    //     cout<<i<<" - > "<<Find(i)<<endl;
    // }
    for (int i = 0; i <= maxRow+maxCol+1; ++i)
    {
        if(Size[i]==1) continue;
        if(Find(i)==i){
            // cout<<i<<" ";
            connectedComponents++;
        } 
    }
    // cout<<endl;
    return stones.size()-connectedComponents;
}
int main(){
    vector<vector<int>> stones={{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout<<removeStones(stones);
}
