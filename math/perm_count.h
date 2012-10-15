/*
 How many valid permutations does n pairs of parentheses.
 */

#define N 4

int res = 0;

void solve(int curr, int has, int n, int array[]) {
    if (curr == n) {
        for (int i = 0; i < n; i++) {
            cout << '(';
            for (int j = 0; j < array[i]; j++)
                cout << ')';
        }
        for (int j = 0; j < n - has; j++)
            cout << ')';

        cout << endl;
        res ++;
        return;
    }

    for (int i = 0; i <= curr - has; i++) {
        array[curr - 1] = i;
        solve(curr + 1, has + i, n, array);
    }
}

void test() {
    res = 0;
    int *array = new int[N];
    solve(1, 0, N, array);
    cout << res << endl;
}
