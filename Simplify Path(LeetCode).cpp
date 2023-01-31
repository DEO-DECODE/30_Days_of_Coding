// Simplify Path(LeetCode)
#include <bits/stdc++.h>
using namespace std;
string simplifyPath(string str)
{
    stack<string> st;
    for(int i=0; i<str.size(); ++i){
        if(str[i]=='/') continue;
        string temp="";
        while (i<str.size()&&str[i]!='/')
        {
            temp+=str[i];
            i++;
        }
        if(temp==".") continue;
        else if(temp==".."){
            if(st.size()>0){
                st.pop();
            }
        }
        else{
           st.push(temp); 
        }
    }
    string ans="";
    while (st.size()>0)
    {
        ans="/"+st.top()+ans;
    }
    if(st.empty())
    ans="/";
    return ans;
    
}
