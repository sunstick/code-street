#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
char graph[110][110];

void flood_fill(int x, int y) {
    if (graph[x][y] == '.' || graph[x][y] == 0)
        return ;
    graph[x][y] = '.';

    flood_fill(x + 1, y);
    flood_fill(x - 1, y);
    flood_fill(x, y + 1);
    flood_fill(x, y - 1);
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int o = 1; o <= t; ++o) {
        cin >> n;
        getchar();

        memset(graph, 0, sizeof(graph));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                graph[i][j] = getchar();
            }
            getchar();
        }

        int total = 0;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (graph[i][j] == 'x') {
                    flood_fill(i, j);
                    total++;
                }
        cout << "Case " << o << ": ";
        cout << total << endl;
    }

    return 0;
}