// https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue
{
    stack<int> mainStk, tempStk;
    int topE;

public:
    MyQueue()
    {
        topE = -1;
    }

    void push(int x)
    {
        mainStk.push(x);
        if (topE == -1)
            topE = x;
    }

    int pop()
    {
        while (mainStk.size() > 1)
        {
            tempStk.push(mainStk.top());
            mainStk.pop();
        }
        if (!tempStk.size())
        {
            topE = -1;
        }
        else
        {
            topE = tempStk.top();
        }
        int ans = mainStk.top();
        mainStk.pop();
        while (tempStk.size())
        {
            mainStk.push(tempStk.top());
            tempStk.pop();
        }
        return ans;
    }

    int peek()
    {
        return topE;
    }

    bool empty()
    {
        return topE == -1;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */