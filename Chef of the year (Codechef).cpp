// Chef of the year (Codechef)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    map<string, string> trackRecord;
    map<string, int> winnerCountry;
    map<string, int> winnerName;
    for (int i = 0; i < n; ++i)
    {
        string name, country;
        cin >> name >> country;
        trackRecord[name] = country;
    }
    // voting
    for (int i = 0; i < m; ++i)
    {
        string str;
        cin >> str;
        // auto itr = find(trackRecord.begin(), trackRecord.end(), str);
        winnerName[str]++;
        string cntry = trackRecord[str];
        winnerCountry[cntry]++;
    }
    int maxVotes = 0;
    string winName = "", wincountry = "";
    auto itr2 = winnerCountry.begin();
    while (itr2 != winnerCountry.end())
    {
        int votes = (*itr2).second;
        string countryName = (*itr2).first;
        if (votes > maxVotes)
        {
            maxVotes = votes;
            wincountry = countryName;
        }
        itr2++;
    }
    maxVotes = 0;
    auto itr3 = winnerName.begin();
    while (itr3 != winnerName.end())
    {
        int votes = (*itr3).second;
        string winnName = (*itr3).first;
        if (votes > maxVotes)
        {
            maxVotes = votes;
            winName = winnName;
        }
        itr3++;
    }
    cout << wincountry << endl
         << winName << endl;
}
