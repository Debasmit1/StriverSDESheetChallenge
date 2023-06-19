// https://leetcode.com/problems/n-queens/description/

class Solution
{

    bool isSafe(vector<vector<int>> &board, int r, int c)
    {
        for (int i = 0; i < r; i++)
        {
            if (board[i][c])
            {
                return 0;
            }
        }

        for (int i = r - 1, j = c - 1; j >= 0 && i >= 0; i--, j--)
        {
            if (board[i][j])
            {
                return 0;
            }
        }

        for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++)
        {
            if (board[i][j])
            {
                return 0;
            }
        }
        return 1;
    }

    void solve(vector<vector<string>> &ans, vector<vector<int>> &board, int r)
    {
        if (r == board.size())
        {
            vector<string> temp;
            for (int i = 0; i < r; i++)
            {
                string str = "";
                for (int j = 0; j < board.size(); j++)
                {
                    if (board[i][j])
                    {
                        str += 'Q';
                    }
                    else
                    {
                        str += '.';
                    }
                }
                temp.push_back(str);
            }
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < board.size(); i++)
        {
            if (isSafe(board, r, i))
            {
                board[r][i] = 1;
                solve(ans, board, r + 1);
                board[r][i] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(ans, board, 0);
        return ans;
    }
};