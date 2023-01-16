class Solution {
public:
    static bool cmp(vector<int> &vec1, vector<int> &vec2)
{
    if (vec1[1] != vec2[1])
    {
        return vec1[1] < vec2[1];
    }
    else
        return vec1[0] > vec2[0];
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), cmp);
    int prevW = -1e9;
    int cnt = 0;
    for (int i = 0; i < intervals.size(); ++i)
    {
        if (intervals[i][0] >= prevW)
        {
            cnt++;
            prevW = intervals[i][1];
        }
    }
    return intervals.size()-cnt;
}
};
