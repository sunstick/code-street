#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int graph[330][330];
int n;
int dist[330];

bool bicolorable(int node) {
    dist[node] = 1;
    queue<int> q;

    q.push(node);

    while (!q.empty()) {
        node = q.front();
        q.pop();

        for (int to = 1; to <= n; to++)
            if (graph[node][to]) {
                if (!dist[to]) {
                    dist[to] = 3 - dist[node];
                    q.push(to);
                } else if (dist[to] == dist[node]) {
                    return false;
                }
            }
    }

    return true;
}

int main(int argc, char const *argv[]) {
    while (cin >> n && n) {
        memset(graph, 0, sizeof(graph));
        memset(dist, 0, sizeof(dist));


        int x, y;
        while (cin >> x >> y && (x || y)) {
            graph[x][y] = 1;
            graph[y][x] = 1;
        }

        bool flag = true;

        for (int i = 1; i <= n; ++i) {
            if (!dist[i]) {
                if (!bicolorable(i)) {
                    flag = false;
                }

            }
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}