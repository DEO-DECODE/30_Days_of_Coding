// Generate IP Addresses(GFG)
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
	unordered_set<string> collec;
	vector<string> finAns;
	static bool checkIp(string str)
	{
		for (int i = 0; i < str.size(); ++i)
		{
			string temp = "";
			while (str[i] != '.' && i < str.size())
			{
				temp += (str[i]);
				i++;
			}
			// cout<<temp<<endl;
			// prefix zeroes
			if (temp.size() > 3)
				return false;
			if (temp.size() >= 1)
			{
				if (temp[0] == '0' && temp.size() > 1)
				{
					return false;
				}
				if (stoi(temp) < 0 || stoi(temp) > 255)
				{
					return false;
				}
			}
		}
		return true;
	}

	void allCombinations(string &s, int ind, int dotCount, unordered_set<string> &collec)
	{
		// out of bound condition
		if (ind >= s.size() + 1)
		{
			return;
		}
		if (dotCount == 0)
		{
			if (checkIp(s))
			{
				collec.insert(s);
			}
			return;
		}
		s.insert(ind, ".");
		allCombinations(s, ind + 2, dotCount - 1, collec);
		s.erase(ind, 1);
		allCombinations(s, ind + 1, dotCount, collec);
	}
	vector<string> genIp(string &s)
	{
		unordered_set<string> collec;
		allCombinations(s, 1, 3, collec);
		vector<string> finAns;
		for (auto strs : collec)
		{
			finAns.push_back(strs);
		}
		return finAns;
	}
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;

		/*generating naively*/
		Solution obj;
		vector<string> str = obj.genIp(s);
		sort(str.begin(), str.end());
		if (str.size() == 0)
			cout << -1 << "\n";
		else
		{
			for (auto &u : str)
			{
				cout << u << "\n";
			}
		}
	}
}
// } Driver Code Ends
