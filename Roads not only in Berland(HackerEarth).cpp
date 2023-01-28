// Roads not only in Berland(HackerEarth)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int parent[N];
int Size[N];
multiset<int> sizeOfGroup;
void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
    sizeOfGroup.insert(1);
}
int Find(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = Find(parent[v]);
}
void Union(int a, int b){
    int a=Find(a);
    int b=Find(b);
    if(a!=b){
        if(Size[a]<Size[b]){
            swap(a,b);
        }
        parent[b]=a;
        Size[a]+=Size[b];
    }
}
int main(){
    int numNode;
    cin>>numNode;
    vector<pair<int, int>> newP, extra;
    for(int i=1; i<=numNode; ++i) make(i);
    for(int i=0; i<numNode-1; ++i){
        int u,v;
        cin>>u>>v;
        if(Find(u)==Find(v)){
            extra.push_back({u,v});
        }
        else{
            Union(u,v);
        }
    }
    for(int i=1; i<=numNode; ++i){
        for(int j=i+1; j<=numNode; ++j){
            if(Find(i)==Find(j)) continue;
            else{
                Union(i,j);
                newP.push_back({i,j});
            }
        }
    }
    return 0;
}
