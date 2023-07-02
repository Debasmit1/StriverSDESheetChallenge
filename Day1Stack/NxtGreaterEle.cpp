// https://leetcode.com/problems/next-greater-element-i/description/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mpp;
        stack<int> stk;
        mpp[nums2[nums2.size() - 1]] = -1;
        stk.push(nums2[nums2.size() - 1]);

        for (int i = nums2.size() - 2; i >= 0; i--)
        {
            while (stk.size() && stk.top() <= nums2[i])
                stk.pop();
            if (stk.size())
            {
                mpp[nums2[i]] = stk.top();
            }
            else
            {
                mpp[nums2[i]] = -1;
            }
            stk.push(nums2[i]);
        }

        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(mpp[nums1[i]]);
        }

        return ans;
    }
};