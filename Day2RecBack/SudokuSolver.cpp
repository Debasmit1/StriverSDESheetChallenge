// https://leetcode.com/problems/sudoku-solver/description/

class Solution
{

    bool isValid(vector<vector<char>> &board, int r, int c, char &ch)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][c] == ch)
                return 0;
            if (board[r][i] == ch)
                return 0;
            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch)
                return 0;
        }
        return 1;
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isValid(board, i, j, ch))
                        {
                            board[i][j] = ch;

                            if (solve(board))
                            {
                                return 1;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};