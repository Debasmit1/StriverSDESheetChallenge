// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution
{

    bool isBool(string &str, int s, int e)
    {
        while (s < e)
        {
            if (str[s] != str[e])
            {
                return 0;
            }
            s++, e--;
        }
        return 1;
    }

    void solve(vector<vector<string>> &ans, vector<string> &temp, int idx, string s)
    {
        if (idx == s.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < s.size(); i++)
        {
            if (isBool(s, idx, i))
            {
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(ans, temp, i + 1, s);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans, temp, 0, s);
        return ans;
    }
};