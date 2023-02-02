#include <bits/stdc++.h>
using namespace std;
// HIghest Value Palindrme(Hackerrank)
int main()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<int> changed(n, 0);
    for (int i = 0; i < n / 2; ++i)
    {
        if (str[i] != str[n - 1 - i])
        {
            if (str[i] > str[n - 1 - i])
            {
                str[n - 1 - i] = str[i];
                changed[n - 1 - i] = 1;
            }
            else
            {
                str[i] = str[n - 1 - i];
                changed[i] = 1;
            }
            k--;
        }
    }
    if (k < 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        int lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            if (k == 0)
                break;
            if (lo == hi && k > 0)
            {
                str[lo] = '9';
                k--;
                break;
            }
            else if(str[lo]<'9')
            {
                if (changed[lo] == 0 && changed[hi] == 0 && k >= 2)
                {
                    str[lo] = '9';
                    str[hi] = '9';
                    k -= 2;
                }
                else if ((changed[lo] == 1 || changed[hi] == 1) && k >= 1)
                {
                    str[lo] = '9';
                    str[hi] = '9';
                    k -= 1;
                }
            }
            lo++;
            hi--;
        }
        cout << str << endl;
    }
}
