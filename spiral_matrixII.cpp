class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > mat(n);
        if (n == 0)
            return mat;

        for (int i = 0; i < n; i++)
            mat[i] = vector<int>(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = 0;

        mat[0][0] = 1;
        int value = 1;
        int x = 0; int y = 0;

        while (value < n * n) {
            // top right
            while (y + 1 < n && !mat[x][y + 1])
                mat[x][++y] = ++value;

            // right down
            while (x + 1 < n && !mat[x + 1][y])
                mat[++x][y] = ++value;

            // bottom left
            while (y - 1 >= 0 && !mat[x][y - 1])
                mat[x][--y] = ++value;

            // left up
            while (x - 1 >= 0 && !mat[x - 1][y])
                mat[--x][y] = ++value;
        }

        return mat;
    }
};