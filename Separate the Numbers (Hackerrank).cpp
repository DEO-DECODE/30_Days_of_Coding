//Separate the Numbers (Hackerrank)
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin>>q;
	while (q--)
	{
		string str;
		cin>>str;
		bool check=true;
		for(int i=1; i<=str.size()/2; ++i){
			string sbst=str.substr(0,i);
			string temp=sbst;
			string temp2="";
			long long initialVal=(stoll(sbst));
			long long val=initialVal;
			while (temp.size()<str.size())
			{
				temp2=to_string(++val);
				temp+=temp2;
			}
			if(temp==str){
				cout<<"YES"<<" "<<initialVal<<endl;
				check=false;
				break;
			}
		}
		if(check){
			cout<<"NO"<<endl;
		}
	}
	
}
