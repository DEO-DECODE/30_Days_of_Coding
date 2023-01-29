//Path queries(CODEFORCES)
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int Parent[N], Size[N];
void Make(int v){
	Parent[v]=v;
	Size[v]=1;
}
int Find(int v){
	if(Parent[v]==v) return v;
	return Parent[v]=Find(Parent[v]);
}
void Union(int a, int b){
	a=Find(a), b=Find(b);
	if(a!=b){
		if(Size[a]<Size[b])
		{
			swap(a,b);
		}
		Size[a]+=Size[b];
		Parent[b]=a;
	}
}
int main(){
	int n,q;
	cin>>n>>q;
	vector<pair<int, pair<int, int>>> vec;
	for(int i=1; i<=n; ++i){
		Make(i);
	}
	vector<pair<int, int>> quer;
	for (int i = 0; i < n-1; i++)
	{
		int qi;
		cin>>qi;
		quer.push_back({qi,i});
	}
	sort(vec.begin(), vec.end());
	sort(quer.begin(), quer.end());
	auto itr=vec.begin();
	int count=0;
	vector<int> res(q+1);
	for(int i=0; i<quer.size(); ++i){
		auto pr=quer[i];
		int x=pr.first;
		while ((*itr).first<=x&&itr!=vec.end())
		{
			auto pr=(*itr).second;
			int xi=pr.first, yi=pr.second;
			xi=Find(xi), yi=Find(yi);
			count+=Size[xi]*Size[yi];
			Union(xi,yi);
			itr++;
		}
		res[pr.second]=count;
	}
	for(int i=0; i<q; ++i){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
