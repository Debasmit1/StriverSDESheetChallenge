// https://leetcode.com/problems/sliding-window-maximum/description/
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        map<int, int> mpp;
        for (int i = 0; i < k; i++)
        {
            mpp[nums[i]]++;
        }
        vector<int> ans;
        ans.push_back(mpp.rbegin()->first);

        for (int i = k; i < nums.size(); i++)
        {
            mpp[nums[i - k]]--;
            if (mpp[nums[i - k]] == 0)
                mpp.erase(nums[i - k]);
            mpp[nums[i]]++;
            ans.push_back(mpp.rbegin()->first);
        }
        return ans;
    }
};