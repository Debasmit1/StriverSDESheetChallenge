// https://leetcode.com/problems/top-k-frequent-elements/description/
class Solution
{
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        vector<pair<int, int>> vals;
        for (auto it : mpp)
        {
            vals.push_back(it);
        }
        sort(vals.begin(), vals.end(), cmp);

        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(vals[i].first);
        }
        return ans;
    }
};