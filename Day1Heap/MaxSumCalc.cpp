// https://www.interviewbit.com/problems/maximum-sum-combinations/

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<int> ans;
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> stt;

    int n = A.size();
    pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
    stt.insert({n - 1, n - 1});

    for (int cnt = 0; cnt < C; cnt++)
    {
        auto it = pq.top();
        pq.pop();

        ans.push_back(it.first);

        int iIdx = it.second.first;
        int jIdx = it.second.second;

        int temp1 = A[iIdx] + B[jIdx - 1];
        int temp2 = A[iIdx - 1] + B[jIdx];

        if (stt.find({iIdx, jIdx - 1}) == stt.end())
        {
            pq.push({temp1, {iIdx, jIdx - 1}});
            stt.insert({iIdx, jIdx - 1});
        }
        if (stt.find({iIdx - 1, jIdx}) == stt.end())
        {
            pq.push({temp2, {iIdx - 1, jIdx}});
            stt.insert({iIdx - 1, jIdx});
        }
    }

    return ans;
}
