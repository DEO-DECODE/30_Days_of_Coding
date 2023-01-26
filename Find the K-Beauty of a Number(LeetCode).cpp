// Find the K-Beauty of a Number(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int divisorSubstrings(int num, int k)
{
    string str = "";
    int temp = num;
    while (num > 0)
    {
        str += to_string(num % 10);
        num = num / 10;
    }
    reverse(str.begin(), str.end());
    cout << str << endl;
    string sbstr = "";
    int i = k, cnt = 0;
    while (i < str.size())
    {
        sbstr = str.substr(i - k, k);
        int numb = stoi(sbstr);
        // cout << i << " " << numb << endl;
        // cout<<numb<<endl;
        if ((numb != 0))
        {
            if ((temp % numb == 0))
                cnt++;
        }

        i++;
    }
    sbstr = str.substr(i - k, k);
    // cout << i << " " << sbstr << endl;
    int numb = stoi(sbstr);
    if ((numb != 0))
    {
        if ((temp % numb == 0))
            cnt++;
    }
    return cnt;
}
int main()
{
    int num = 430043, k = 2;
    cout << divisorSubstrings(num, k);
}
