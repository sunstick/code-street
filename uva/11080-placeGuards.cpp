#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

int graph[210][210];
int n, l;
int dist[210];

int bicolorable(int node) {

    int t1 = 0;
    int t2 = 0;
    dist[node] = 1;
    t1 ++;
    queue<int> q;

    q.push(node);

    while (!q.empty()) {
        node = q.front();
        q.pop();

        for (int to = 0; to < n; to++)
            if (graph[node][to]) {
                if (!dist[to]) {
                    dist[to] = 3 - dist[node];
                    if (dist[to] == 1)
                        t1 ++;
                    else
                        t2 ++;
                    q.push(to);
                } else if (dist[to] == dist[node]) {
                    return -1;
                }
            }
    }

    return min(t1, t2);
}

int main(int argc, char const *argv[]) {
    int t = 0;
    cin >> t;

    while (t--) {
        cin >> n >> l;
        memset(graph, 0, sizeof(graph));
        memset(dist, 0, sizeof(dist));

        while (l--) {
            int x, y;
            cin >> x >> y;
            graph[x][y] = 1;
            graph[y][x] = 1;
        }

        int total = 0;

        for (int i = 0; i < n; ++i) {
            if (!dist[i]) {
                int step = bicolorable(i);
                if (step == -1) {
                    total = -1;
                    break;
                } else
                    total += max(step, 1);
            }
        }

        cout << total << endl;
    }

    return 0;
}