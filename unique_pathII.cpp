/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

int path[110][110];

void solve(int m, int n, vector<vector<int> > &obstacleGrid) {
    path[1][1] = obstacleGrid[0][0] ? 0 : 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1)
                continue ;
            if (obstacleGrid[i - 1][j - 1] == 1)
                path[i][j] = 0;
            else {
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }
    }
}


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        solve(m, n, obstacleGrid);

        return path[m][n];
    }
};