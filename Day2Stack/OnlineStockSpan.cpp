// https://leetcode.com/problems/online-stock-span/description/

class StockSpanner
{
    stack<pair<int, int>> stk;
    int cnt{};

public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        cnt++;
        while (stk.size() && stk.top().first <= price)
            stk.pop();
        if (!stk.size())
        {
            stk.push({price, cnt});
            return cnt;
        }
        else
        {
            int ans = cnt - stk.top().second;
            stk.push({price, cnt});
            return ans;
        }
    }
};