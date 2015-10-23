#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char data[6][6];
int can[6][6];
int n, av;

void reset(int i, int j, int offset) {
    can[i][j] += offset;
    for (int k = j + 1; k <= n && data[i][k] != 'X'; k++) // left to right
        can[i][k] += offset;

    for (int k = j - 1; k >= 1 && data[i][k] != 'X'; k--) // right to left
        can[i][k] += offset;

    for (int k = i + 1; k <= n && data[k][j] != 'X'; k++) // top to down
        can[k][j] += offset;

    for (int k = i - 1; k >= 1 && data[k][j] != 'X'; k--) // down to top
        can[k][j] += offset;
}

int search(int cur) {
    int res = cur;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (can[i][j] == 0) {
                reset(i, j, 1);
                int val = search(cur + 1);
                res = max(res, val);
                reset(i, j, -1);
            }
    return res;
}

int main() {
    while (cin >> n && n) {
        getchar();
        memset(can, 0, sizeof(can));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> data[i][j];
                if (data[i][j] == 'X')
                    can[i][j] = 100000;
            }
            getchar();
        }
        cout << search(0) << endl;
    }
    return 0;
}
