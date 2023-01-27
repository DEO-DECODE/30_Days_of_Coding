#include<bits/stdc++.h>
using namespace std;
//STEPPING NUMBER (GFG)
/*
A number is called a stepping number if all adjacent digits have an absolute difference of 1, e.g. '321' is a
Stepping Number while 421 is not. Given two integers n and m, find the count of all the stepping numbers in 
the range [n, m]
*/

vector<int> answer;
class Solution{
public:
;
    void allnum(int st, int &en, int val, int &count){
        if(val>en) return;
        if(val>=st&&val<=en) {
            count++;
            answer.push_back(val);
        }
        int lastdig=val%10;
        if(lastdig!=0){
            // int newnum=(lastdig*10)+(lastdig-1);
            allnum(st, en,val*10+(lastdig-1), count);
        }
        if(lastdig!=9){
            // int newnum=(lastdig*10)+(lastdig+1);
            allnum(st, en,val*10+(lastdig+1), count);
        }
    }
    int steppingNumbers(int n, int m)
    {
        // Code Here
        int count=0;
        if(n==0) count++;
        for(int i=1; i<=9; ++i)
        allnum(n,m,i,count);
        return count;
    }
};


// { Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
        sort(answer.begin(), answer.end());
        for(auto val: answer){
            cout<<val<<" ";
        }
    }
	return 0;
}
