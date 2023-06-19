// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution
{

    bool isCheck(int nR, int nC, int n, vector<vector<int>> &m)
    {
        return (nR >= 0 && nR < n && nC >= 0 && nC < n && m[nR][nC]);
    }

    void solve(vector<vector<int>> &m, int n, int r, int c, vector<vector<int>> &visit, vector<string> &ans, string &str)
    {

        if (r == n - 1 && c == n - 1)
        {
            ans.push_back(str);
            return;
        }

        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nR = r + del_row[i];
            int nC = c + del_col[i];

            if (isCheck(nR, nC, n, m) && !visit[nR][nC])
            {
                visit[nR][nC] = 1;
                if (i == 0)
                {
                    str.push_back('U');
                }
                else if (i == 1)
                {
                    str.push_back('R');
                }
                else if (i == 2)
                {
                    str.push_back('D');
                }
                else
                {
                    str.push_back('L');
                }
                solve(m, n, nR, nC, visit, ans, str);
                str.pop_back();
                visit[nR][nC] = 0;
            }
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here

        vector<string> ans;
        vector<vector<int>> visit(n, vector<int>(n, 0));
        string str = "";
        visit[0][0] = 1;
        if (m[0][0])
            solve(m, n, 0, 0, visit, ans, str);
        return ans;
    }
};