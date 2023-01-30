//Palindrome Index(Hackerrank)
#include <bits/stdc++.h>
using namespace std;
/*
Str=b b a z a x b b
    0 1 2 3 4 5 6 7
the first index where case of not match occur was
at 2 and 5 but deteting character at 2 will result in
str1= b b z a x b b
but deleting at 5 will result in
str2= b b a z a b b
*/
bool isPalindrome(string str1)
{
    string str2 = str1;
    reverse(str1.begin(), str1.end());
    if (str1 == str2)
        return true;
    return false;
}
int main(){
    int q;
    cin>>q;
    while (q--)
    {
        string str1;
        cin>>str1;
        string str2=str1;
        reverse(str2.begin(), str2.end());
        if(str1==str2){
            cout<<0<<endl;
            continue;
        }
        int n=str1.size();
        bool check=false;
        for(int i=0; i<str1.size()/2; ++i){
            if(str1[i]!=str1[n-1-i]){
                string aux=str1;
                string temp1=str1.erase(i,1);
                string temp2=aux.erase(n-1-i,1);
                if(isPalindrome(temp1)){
                    cout<<i<<endl;
                    check=true;
                    break;
                }
                else if(isPalindrome(temp2)){
                    cout<<n-1-i<<endl;
                    check=true;
                    break;
                }
            }
        }
        if (!check)
        {
            cout << -1 << endl;
        }
    }
    
}
