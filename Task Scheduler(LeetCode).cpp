// Task Scheduler(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int leastInterval(vector<char>& tasks, int n) {
        int counter[26] = {0};
        for (char task : tasks) {
            counter[task - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (counter[i]) {
                pq.push(counter[i]);
            }
        }
        int time = 0;
        while (!pq.empty()) {
            vector<int> remaining;
            int all = n + 1;
            while (all && !pq.empty()) {
                int counts = pq.top();
                pq.pop();
                if (--counts) {
                    remaining.push_back(counts);
                }
                time++;
                all--;
            }
            for (int counts : remaining) {
                pq.push(counts);
            }
            if (pq.empty()) {
                break;
            }
            time += all;
        }
        return time;
    }
