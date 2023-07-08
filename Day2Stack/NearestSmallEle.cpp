// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &A)
{

    stack<int> stk;
    vector<int> ans;
    if (!A.size())
        return ans;
    ans.push_back(-1);
    stk.push(A[0]);

    for (int i = 1; i < A.size(); i++)
    {
        while (stk.size() && A[i] <= stk.top())
            stk.pop();
        if (stk.size())
        {
            ans.push_back(stk.top());
        }
        else
        {
            ans.push_back(-1);
        }
        stk.push(A[i]);
    }

    return ans;
}
