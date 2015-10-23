#include <iostream>
#include <cstring>
#include <cstdio>
#define N 8

using namespace std;

int vis[3][20];
int n, x, y, tot;
int ans[N];

void search(int cur) { // cur is column
    if (cur == N) {
        tot++;
        printf("%2d     ", tot);
        for (int i = 0; i < N; i++)
            cout << " " << ans[i] + 1;
        cout << endl;
        return ;
    }

    if (cur == y) {
        search(cur + 1);
        return;
    }

    for (int i = 0; i < N; i++) // i is row
        if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + N]) {
            ans[cur] = i;
            vis[0][i] = vis[1][cur + i] = vis[2][cur - i + N] = 1;
            search(cur + 1);
            vis[0][i] = vis[1][cur + i] = vis[2][cur - i + N] = 0;
        }
}

int main() {
    cin >> n;
    int database_no = 0;
    while (n-- > 0) {
        if (database_no)
            cout << endl;
        database_no++;

        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl;
        cout << endl;
        cin >> x >> y; // x is row, y is column

        tot = 0;
        memset(vis, 0, sizeof(vis));
        memset(ans, 0, sizeof(ans));
        --y;
        --x;
        ans[y] = x;
        vis[0][x] = vis[1][x + y] = vis[2][y - x + N] = 1;
        search(0);
    }
    return 0;
}
