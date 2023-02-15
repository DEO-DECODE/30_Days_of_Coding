//Check If The String Is A Palindrome(CodingNinjas)
#include <bits/stdc++.h>
using namespace std;
char lowercase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool valid(char ask)
{
    if ((ask >= 'a' && ask <= 'z') || (ask >= 'A' && ask <= 'Z') || (ask >= '0' && ask <= '9'))
    {
        return true;
    }
    else
        return false;
}

bool checkPalindrome(string s)
{
    string temp;
    for (int i = 0; i < s.size(); i++)
    {
        if (valid(s[i]))
        {
            temp.push_back(s[i]);
        }
    }
    // cout << temp << endl;
    int e = temp.size() - 1;
    int st = 0;
    while (st <= e)
    {
        if (lowercase(temp[st]) != lowercase(temp[e]))
        {
            return false;
        }
        else
        {
            st++;
            e--;
        }
    }
    return true;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        getline(cin, str);
        // cout << endl;
        cout << checkPalindrome(str) << endl;
    }
}
