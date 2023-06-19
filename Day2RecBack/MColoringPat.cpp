// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

class Solution
{

    bool isSafe(int node, bool graph[101][101], int color[], int n, int col)
    {

        for (int i = 0; i < n; i++)
        {
            if (node != i && graph[i][node] && color[i] == col)
            {
                return 0;
            }
        }
        return 1;
    }

    bool solve(int node, bool graph[101][101], int color[], int m, int n)
    {
        if (node == n)
        {
            return 1;
        }

        for (int i = 1; i <= m; i++)
        {
            if (isSafe(node, graph, color, n, i))
            {
                color[node] = i;
                if (solve(node + 1, graph, color, m, n))
                    return 1;
                color[node] = 0;
            }
        }
        return 0;
    }

public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        // your code here
        int color[n] = {0};

        return solve(0, graph, color, m, n);
    }
};