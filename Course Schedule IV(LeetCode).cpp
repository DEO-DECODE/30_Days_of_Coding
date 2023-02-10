// Course Schedule IV(LeetCode).
#include <bits/stdc++.h>
using namespace std;
vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
{
    vector<vector<int>> graph(numCourses);
    vector<vector<bool>> orderOfCourse(numCourses, vector<bool> (numCourses,false));
    vector<int> inDeg(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); ++i)
    {
        graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        inDeg[prerequisites[i][1]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size() > 0)
    {
        auto currv = q.front();
        q.pop();
        // order.push_back(currv);
        for (auto childv : graph[currv])
        {
            orderOfCourse[currv][childv]=true;
             for (int i=0; i<numCourses; ++i)
            {
                if(orderOfCourse[i][currv]==1){
                    orderOfCourse[i][childv]=1;
                }
            }
            inDeg[childv]--;
            if (inDeg[childv] == 0)
            {
                q.push(childv);
            } 
        }
    }
    vector<bool> ans;
    for (int i = 0; i < queries.size(); ++i)
    {
        int preReq = queries[i][0];
        int crs = queries[i][1];
        ans.push_back(orderOfCourse[preReq][crs]);
    }
    return ans;
}
