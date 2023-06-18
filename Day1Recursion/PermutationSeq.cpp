// https://leetcode.com/problems/permutation-sequence/description/

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> vals;
        for (int i = 1; i <= n; i++)
        {
            fact *= i;
            vals.push_back(i);
        }
        k--;
        string ans = "";
        while (n)
        {
            int size = fact / n;
            int idx = k / size;
            ans += to_string(vals[idx]);
            vals.erase(vals.begin() + idx);
            k = k % size;
            fact /= n;
            n--;
        }
        return ans;
    }
};