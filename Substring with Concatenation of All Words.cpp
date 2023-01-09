#include <bits/stdc++.h>
using namespace std;
bool isPermOfWords(vector<string> words, string theWord)
{
    int sizeOfEachWord = words[0].size();
    int totalWords = theWord.size() / sizeOfEachWord;
    int cnt = 0;
    int index = 0;
    cout << "\n-----------\n";
    cout << theWord << endl;
    while (cnt < totalWords)
    {
        string temp = theWord.substr(index, sizeOfEachWord);
        auto itr = find(words.begin(), words.end(), temp);
        cout << temp << endl;
        if (itr == words.end())
            return false;

        words.erase(itr);

        cnt++;
        index += sizeOfEachWord;
    }
    cout << endl;
    return true;
}
vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> ans;
    int szofstr = (words.size() * words[0].size());
    for (int i = 0; i <= s.size() - szofstr; ++i)
    {
        if (isPermOfWords(words, s.substr(i, szofstr)))
        {
            ans.push_back(i);
        }
    }
    return ans;
}
int main()
{
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word", "good", "best", "good"};
    auto ans = findSubstring(s, words);
    for (auto val : ans)
    {
        cout << val << " ";
    }
}
