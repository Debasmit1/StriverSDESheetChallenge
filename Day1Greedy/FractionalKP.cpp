// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

class Solution
{
    bool static cmp(pair<Item, double> &a, pair<Item, double> &b)
    {
        return a.second > b.second;
    }

public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<Item, double>> vals;
        for (int i = 0; i < n; i++)
        {
            double x = (double)arr[i].value / (double)arr[i].weight;
            vals.push_back(make_pair(arr[i], x));
        }
        sort(vals.begin(), vals.end(), cmp);
        double ans = 0.0;

        int i = 0;
        while (W && i < n)
        {
            if (vals[i].first.weight <= W)
            {
                ans += vals[i].first.value;
                W -= vals[i].first.weight;
            }
            else
            {
                ans += vals[i].second * W;
                W = 0;
            }
            i++;
        }

        return ans;
    }
};