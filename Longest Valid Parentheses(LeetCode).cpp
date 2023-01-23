#include <bits/stdc++.h>
using namespace std;
// Longest Valid Parentheses(LeetCode)
int longestValidParentheses(string s) {
    stack<char> brackets;
    stack<int> st;
    int ans=0;
    st.push(-1);
    for(int i=0; i<s.size(); ++i){
        if(s[i]=='('){
            brackets.push('(');
            st.push(i);
        }
        else{
            if(brackets.empty()){
                st.push(i);
            }
            else{
                st.pop();
                brackets.pop();
                ans=max(ans, i-st.top());
            }
        }
    }    
    return ans;
}
