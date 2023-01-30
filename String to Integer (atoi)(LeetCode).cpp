// String to Integer (atoi)(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int myAtoi(string str)
{
	int n = str.size();
	if (n == 0)
		return 0;
	int i = 0;
	while (i < n && str[i] == ' ')
	{
		i++;
	}
	str = str.substr(i);
	int sign = 1;
	long long ans = 0;
	if (str[0] == '-')
		sign = -1;
	(str[0] == '-' || str[0] == '+') ? i = 1 : i = 0;
	while (i<n)
	{
		if(str[i]==' '||!isdigit(str[i])) break;
		ans=ans*10+(str[i]-'0');
		if(sign==1&&ans>INT_MAX) return INT_MAX;
		if(sign==-1&&ans<INT_MIN) return INT_MIN;
		i++;
	}
	return (int) (sign*ans);
}
