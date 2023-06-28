// https://leetcode.com/problems/implement-stack-using-queues/description/

class MyStack
{
    queue<int> mainQ;
    int topE;

public:
    MyStack()
    {
        topE = -1;
    }

    void push(int x)
    {
        mainQ.push(x);
        topE++;
    }

    int pop()
    {
        int size = mainQ.size();
        topE--;
        while (size > 1)
        {
            mainQ.push(mainQ.front());
            mainQ.pop();
            size--;
        }
        int ans = mainQ.front();
        mainQ.pop();
        return ans;
    }

    int top()
    {
        int size = mainQ.size();
        while (size > 1)
        {
            mainQ.push(mainQ.front());
            mainQ.pop();
            size--;
        }
        int ans = mainQ.front();
        mainQ.push(mainQ.front());
        mainQ.pop();
        return ans;
    }

    bool empty()
    {
        return topE == -1;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */