// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

class Solution
{
    void solve(vector<int> &arr, int N, int idx, int sum, vector<int> &ans)
    {
        if (idx == N)
        {
            ans.push_back(sum);
            return;
        }

        solve(arr, N, idx + 1, sum, ans);
        solve(arr, N, idx + 1, sum + arr[idx], ans);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        int sum{};
        vector<int> ans;
        solve(arr, N, 0, 0, ans);
        return ans;
    }
};