#include <bits/stdc++.h>
using namespace std;
static bool cmp(vector<int> &vec1, vector<int> &vec2)
{
    if (vec1[1] != vec2[1])
    {
        return vec1[1] < vec2[1];
    }
    else
        return vec1[0] > vec2[0];
}
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), cmp);
    int arrows=1;
    int end=points[0][1];
    for(int i=1; i<points.size(); ++i){
        if(points[i][0]>end){
            end=points[i][1];
            arrows++;
        }
    }
    return arrows;
}
