/*
Given a matrix(2d array) with m rows and n columns. Print the matrix in spiral order.
*/

#define x 500
#define y 600

int matrix[x][y];

void spiral_print(int m, int n, int k) {
    if (m <= 0 || n <= 0)
        return ;

    if (m == 1) {
        for (int j = 0; j < n; j++)
            cout << matrix[k][k + j] << " ";
        return;
    }
    if (n == 1) {
        for (int i = 0; i < m; i++)
            cout << matrix[i + k][k] << " ";
        return;
    }

    for (int i = k; i < n + k - 1; i++) {
        cout << matrix[k][i] << " ";
    }

    for (int i = k; i < m + k - 1; i++) {
        cout << matrix[i][n + k - 1] << " ";
    }

    for (int i = n + k - 1; i >= k + 1; i--) {
        cout << matrix[m + k - 1][i] << " ";
    }

    for (int i = m + k - 1; i >= k + 1; i--) {
        cout << matrix[i][k] << " ";
    }

    spiral_print(m - 2, n - 2, k + 1);
}