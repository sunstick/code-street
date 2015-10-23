/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size(); // m rows
        int n = matrix[0].size(); // n columns

        vector<int> rows(m);
        vector<int> columns(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!matrix[i][j]) {
                    rows[i] = 1;
                    columns[j] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i] || columns[j])
                    matrix[i][j] = 0;
            }
        }
    }
};