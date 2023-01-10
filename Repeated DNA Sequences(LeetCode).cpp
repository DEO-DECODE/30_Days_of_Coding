#include <bits/stdc++.h>
using namespace std;
// Repeated DNA Sequences(LeetCode)
vector<string> findRepeatedDnaSequences(string s)
{
    /*
    return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule
    */
   vector<string> vec;
   unordered_map<string, int> mp;
    for (int i = 0; i <= s.size() - 10; ++i)
    {
        string temp=s.substr(i,10);
        if(mp[temp]>=1){
            auto it=find(vec.begin(), vec.end(), temp);
            if(it==vec.end())
            vec.push_back(temp);
        }
        mp[temp]++;
    }
    return vec;
}
