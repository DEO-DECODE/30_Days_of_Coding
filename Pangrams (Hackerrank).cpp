//Pangrams (Hackerrank)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    unordered_set<char> st;
    for(int i=0; i<str.size(); ++i){
        if(isalpha(str[i])){
            if(isupper(str[i])){
                st.insert(tolower(str[i]));
            }
            else{
                st.insert(str[i]);
            }
        }
    }
    st.size()==26?cout<<"pangram":cout<<"not pangram";
}
