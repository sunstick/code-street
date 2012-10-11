/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.
*/

int path[110][110];

void solve(int m, int n) {
    path[1][1] = 1;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            path[i][j] = path[i - 1][j] + path[i][j - 1];
        }
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        solve(m, n);
        return path[m][n];
    }
};
