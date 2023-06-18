// https://leetcode.com/problems/subsets-ii/description/

class Solution
{

    void solve(vector<int> &nums, int idx, vector<int> temp, vector<vector<int>> &ans)
    {
        ans.push_back(temp);

        for (int i = idx; i < nums.size(); i++)
        {
            if (idx < i && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            solve(nums, i + 1, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(nums, 0, temp, ans);
        return ans;
    }
};