#include <bits/stdc++.h>
using namespace std;
const int N =1e5+7;
int ans=0;
//Word Ladder (LEETCODE)
 int ladderLength(string beginw, string endw, vector<string>& wordList) {
        int step=0;
        unordered_set<string> dict;
        auto itr=find(wordList.begin(), wordList.end(), endw);
        if(itr==wordList.end()) return 0;
        int sz=beginw.length();
        for(int i=0; i<wordList.size(); i++){
            dict.insert(wordList[i]);//INorder to achieve O(1) complexity
        }
        queue<string> q;
        q.push(beginw);
        while (!q.empty())
        {
            step++;
            int qsz=q.size();
            for(int i=0; i<qsz; ++i){
                string temp=q.front();
                q.pop();
                for(int j=0; j<sz; ++j){
                    char qr=temp[j];
                    for(char x='a'; x<='z'; x++){
                        temp[j]=x;
                        if(temp==endw) return step+1;
                        if(dict.find(temp)==dict.end()) continue;
                        dict.erase(temp);//so that process repeat naa ho kisi doosre word ke liye
                        q.push(temp);

                    }
                    temp[j]=qr;
                }
            }
        }
        return 0;
}
int main(){
    string begin="hit";
    string end="cog";
    vector<string> wordlist={"hot","dot","dog","lot","log","cog"};
    int x=ladderLength(begin,end,wordlist);
    cout<<x;
}
