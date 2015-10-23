#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;

int matrix[110][110];
int b[110];

int max_sum_subarray(int *array, int n) {
    int sum = INT_MIN;
    int maxsum = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if (sum < 0)
            sum = array[i];
        else
            sum += array[i];
        maxsum = max(maxsum, sum);
    }

    return maxsum;
}

int max_sum_submatrix(int n) {
    int maxsum = INT_MIN;
    for (int x = 0; x < n; ++x) {
        memset(b, 0, sizeof(b));
        for (int y = x; y < n; ++y) {
            for (int i = 0; i < n; ++i) {
                b[i] += matrix[i][y];
            }

            maxsum = max(maxsum, max_sum_subarray(b, n));
        }
    }

    return maxsum;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << max_sum_submatrix(n) << endl;
    return 0;
}