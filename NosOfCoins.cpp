// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution
{

public:
    int minCoins(int coins[], int M, int V)
    {
        // Your code goes here
        vector<int> dp(V + 1, V + 1);
        dp[0] = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 1; j < V + 1; j++)
            {
                if (coins[i] <= j)
                {
                    dp[j] = min(1 + dp[j - coins[i]], dp[j]);
                }
            }
        }
        return dp[V] == V + 1 ? -1 : dp[V];
    }
};