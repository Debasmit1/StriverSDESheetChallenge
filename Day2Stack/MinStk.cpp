// https://leetcode.com/problems/min-stack/description/
class MinStack
{
    multiset<int> stt;
    stack<int> stk;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        stt.insert(val);
        stk.push(val);
    }

    void pop()
    {
        stt.erase(stt.find(stk.top()));
        stk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return *stt.begin();
    }
};