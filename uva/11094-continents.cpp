#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char graph[30][30];

int total;
char land;
int m, n;

void move(int x, int y) {
    if (graph[x][y] != land)
        return ;

    graph[x][y] = 0;

    total++;
    move(x + 1, y);
    move(x - 1, y);
    move(x, y % n + 1);
    move(x, (y - 2 + n) % n + 1);
}

int main(int argc, char const *argv[]) {
    while (scanf("%d %d", &m, &n) == 2) {
        getchar();

        memset(graph, 0 , sizeof(graph));


        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                graph[i][j] = getchar();
            }
            getchar();
        }

        int x, y;
        scanf("%d %d", &x, &y);
        x++; y++;

        land = graph[x][y];
        total = 0;
        move(x, y);
        int res = 0;

        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                total = 0;
                move(i, j);
                res = max(res, total);
            }

        cout << res << endl;
    }
    return 0;
}