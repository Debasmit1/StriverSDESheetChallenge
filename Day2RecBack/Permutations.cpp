// https://leetcode.com/problems/permutations/description/

// With extra space

class Solution
{

    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, vector<int> &freq)
    {
        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i] = 1;
                solve(nums, ans, ds, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        solve(nums, ans, ds, freq);
        return ans;
    }
};

// Without extra space
class Solution
{

    void solve(vector<vector<int>> &ans, vector<int> nums, int idx)
    {
        if (idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[idx]);
            solve(ans, nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        solve(ans, nums, 0);
        return ans;
    }
};