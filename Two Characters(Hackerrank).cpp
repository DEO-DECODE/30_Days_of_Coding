// Two Characters(Hackerrank)
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int len;
	string str;
	cin >> len >> str;
	unordered_set<char> stS;
	for (int i = 0; i < str.size(); ++i)
	{
		stS.insert(str[i]);
	}
	vector<char> vec;
	for (auto itr = stS.begin(); itr != stS.end(); ++itr)
	{
		vec.push_back(*itr);
	}
	int ans = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = i + 1; j < vec.size(); ++j)
		{
			char ch1 = vec[i], ch2 = vec[j];
			stack<char> st;
			int cnt = 0;
			for (int i = 0; i < str.size(); ++i)
			{
				if (!st.empty())
				{
					if (st.top() == str[i])
					{
						cnt = 0;
						break;
					}
				}
				if (str[i] == ch1 || str[i] == ch2)
				{
					st.push(str[i]);
					cnt++;
				}
			}
			ans=max(ans, cnt);
		}
	}
	cout<<ans;
}
