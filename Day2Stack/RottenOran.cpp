// https://leetcode.com/problems/rotting-oranges/description/

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int two{}, tot{}, row(grid.size()), col(grid[0].size());

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                    two++;
                    tot++;
                }
                else if (grid[i][j] == 1)
                {
                    tot++;
                }
            }
        }

        if (two == tot)
            return 0;

        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};
        int t{};
        while (q.size())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int j = 0; j < 4; j++)
                {
                    int nr = r + del_row[j];
                    int nc = c + del_col[j];

                    if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        two++;
                        q.push({nr, nc});
                    }
                }
            }
            if (q.size())
                t++;
        }
        if (tot == two)
            return t;
        return -1;
    }
};