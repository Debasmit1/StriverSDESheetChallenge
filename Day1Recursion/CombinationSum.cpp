// https://leetcode.com/problems/combination-sum/description/

class Solution
{

    void solve(vector<vector<int>> &ans, vector<int> temp, int idx, vector<int> &can, int t)
    {
        if (t < 1 || idx == can.size())
        {
            if (!t)
            {
                ans.push_back(temp);
            }
            return;
        }

        if (can[idx] <= t)
        {
            temp.push_back(can[idx]);
            solve(ans, temp, idx, can, t - can[idx]);
            temp.pop_back();
        }
        solve(ans, temp, idx + 1, can, t);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &can, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, 0, can, target);
        return ans;
    }
};