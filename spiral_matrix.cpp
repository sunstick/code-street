// this solution is very weird
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;

        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;

        int level = 0;
        while (res.size() != m * n) {

            for (int i = level; i < n - level; i++)
                res.push_back(matrix[level][i]);
            if (res.size() == m * n)
                break;

            for (int i = level + 1; i < m - level - 1; i++)
                res.push_back(matrix[i][n - level - 1]);

            if (res.size() == m * n)
                break;

            for (int i = n - level - 1; i >= level; i--)
                res.push_back(matrix[m - level - 1][i]);
            if (res.size() == m * n)
                break;

            for (int i = m - level - 2; i > level; i--)
                res.push_back(matrix[i][level]);
            if (res.size() == m * n)
                break;
            level++;
        }

        return res;
    }
};