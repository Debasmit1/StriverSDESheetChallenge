// https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder
{

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        (!left.size() || left.top() > num) ? left.push(num) : right.push(num);

        if (left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (left.size() < right.size())
        {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian()
    {
        return (left.size() == right.size()) ? (left.top() + right.top()) / 2.0 : left.top();
    }
};