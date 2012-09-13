#include <vector>
using namespace std;

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