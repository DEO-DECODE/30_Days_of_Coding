#include <bits/stdc++.h>
using namespace std;
//Zigzag conversion leetcode
void zigzag(string str, int numr, string &str1)
{
    vector<string> aux(numr, "");
    int len = str.length();
    int i = 0;
    while (i < len)
    {
        for (int j = 0; j < numr && i < len; ++j)
        {
            aux[j].push_back(str[i++]);
        }
        for (int j = numr - 2; j >= 1 && i < len; j--)
        {
            aux[j].push_back(str[i++]);
        }
    }
    for (auto temp : aux)
    {
        str1 += temp;
    }
}
string convert(string str, int numr)
{
    string str1 = "";
    zigzag(str, numr, str1);
    return str1;
}

int main()
{
    string str;
    cin >> str;
    int numr;
    cin >> numr;
    string str1 = convert(str, numr);
    cout << str1;
}
