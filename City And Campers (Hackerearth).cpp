// { Driver Code Starts
//City And Campers (Hackerearth)
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+3;
int parent[N];
int sizes[N];
multiset<int> sog;
void make(int v){
    parent[v]=v;//Adding independent node.
    sizes[v]=1;
    sog.insert(1);
}
int Find(int v){
    if(parent[v]==v) return v;
    return parent[v]=Find(parent[v]);
}
void merge(int a, int b){
    auto itr=sog.find(sizes[a]);
    if(itr!=sog.end())
    sog.erase(itr);
    auto itr2=sog.find(sizes[b]);
    if(itr2!=sog.end())
    sog.erase(itr2);
    sog.insert(sizes[a]+sizes[b]);
}
void Union(int a, int b){
    if(Find(a)!=Find(b)){
        a=Find(a);
        b=Find(b);
        if(sizes[a]<sizes[b])
        swap(a,b);
        parent[b]=a;
        merge(a,b);
        sizes[a]+=sizes[b];
    }
}
int main(){
    int numnode, numedge;
    cin>>numnode>>numedge;
    for(int i=1; i<=numnode; ++i)
    make(i);
    for(int i=0; i<numedge; ++i){
        int u,v;
        cin>>u>>v;
        Union(u,v);
        int largest=(*--sog.end());
        int smallest=(*sog.begin());
        cout<<largest-smallest<<endl;
    }
    
}
