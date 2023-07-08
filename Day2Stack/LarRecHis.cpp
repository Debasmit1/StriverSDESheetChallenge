// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution
{

    vector<int> findPrev(vector<int> &heights)
    {
        stack<int> stk;
        stk.push(-1);
        vector<int> res(heights.size());
        for (int i = 0; i < heights.size(); i++)
        {
            while (stk.top() != -1 && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            res[i] = stk.top();
            stk.push(i);
        }
        return res;
    }

    vector<int> findSuc(vector<int> &heights)
    {
        stack<int> stk;
        stk.push(-1);
        int n = heights.size();
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (stk.top() != -1 && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            res[i] = stk.top();
            stk.push(i);
        }

        return res;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> prevSmall(n);
        vector<int> nextSmall(n);
        prevSmall = findPrev(heights);
        nextSmall = findSuc(heights);

        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            if (nextSmall[i] == -1)
            {
                nextSmall[i] = n;
            }
            int width = nextSmall[i] - prevSmall[i] - 1;
            int temp = heights[i] * width;
            ans = max(ans, temp);
        }

        return ans;
    }
};