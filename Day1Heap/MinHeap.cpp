// https://www.codingninjas.com/studio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
vector<int> minHeap(int n, vector<vector<int>> &q)
{
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (q[i].size() == 1)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        else
        {
            pq.push(q[i][1]);
        }
    }
    return ans;
}
