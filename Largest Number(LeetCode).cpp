    bool cmp(string &a, string &b)
{
    return a+b> b+a;
}


class Solution {
public:
string largestNumber(vector<int> &nums)
{
    vector<string> vec;
    for (auto val : nums)
    {
        vec.push_back(to_string(val));
    }
    string ans = "";
    sort(vec.begin(), vec.end(), cmp);
    for (auto val : vec)
    {
        // cout << val << endl;
        ans += val;
    }
    int index=0;
    while(index<ans.size()-1&&ans[index]=='0'){
        index++;
    }
    return ans.substr(index);
}
};
