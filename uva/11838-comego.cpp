#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

#define NUM_NODES 2010

using namespace std;

// check if the directed graph is a scc

int n, m;
int dfs_counter;
int vis[NUM_NODES];
int graph[NUM_NODES][NUM_NODES];

void initialize() {
    memset(graph, 0, sizeof(graph));
    memset(vis, 0, sizeof(vis));
    dfs_counter = 0;
}

void dfs_scc(int u) {
    if (vis[u])
        return ;
    vis[u] = 1;
    dfs_counter++;

    for (int i = 0; i < n; ++i) {
        if (graph[u][i] && !vis[i])
            dfs_scc(i);
    }
}

int main(int argc, char const *argv[]) {

    while (cin >> n >> m && (n || m)) {
        initialize();
        while (m--) {
            int x, y, p;
            cin >> x >> y >> p;
            x--; y--;
            graph[x][y] = 1;
            if (p == 2) {
                graph[y][x] = 1;
            }
        }

        dfs_counter = 0;
        dfs_scc(0);

        if (dfs_counter != n) {
            cout << 0 << endl;
            continue;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int temp = graph[i][j];
                graph[i][j] = graph[j][i];
                graph[j][i] = temp;
            }
        }

        dfs_counter = 0;
        memset(vis, 0, sizeof(vis));
        dfs_scc(0);

        if (dfs_counter != n) {
            cout << 0 << endl;
            continue;
        }

        cout << 1 << endl;
    }

    return 0;
}