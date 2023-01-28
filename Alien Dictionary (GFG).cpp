// Alien Dictionary (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findOrder(string dict[], int N, int k)
    {
        vector<vector<int>> g(k);
        vector<int> indeg(k, 0);
        for (int i = 0; i < N - 1; ++i)
        {
            string word1 = dict[i], word2 = dict[i + 1];
            for (int j = 0; j < min(word1.size(), word2.size()); ++j)
            {
                if (word1[j] != word2[j])
                {
                    g[word1[j] - 'a'].push_back(word2[j] - 'a');
                    indeg[word2[j] - 'a']++;
                    break;
                }
            }
        }
        // first k letters are given
        queue<int> q;
        string ans="";
        for(int i=0; i<k; ++i){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while (q.size()>0)
        {
            int currv=q.front(); q.pop();
            ans+='a'+currv;
            for(auto childv: g[currv]){
                indeg[childv]--;
                if(indeg[childv]==0){
                    q.push(childv);
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b)
{
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++)
    {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
