#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int graph[110][110];
int visited[110];
int n, m;
std::vector<int> ordering;

void dfs(int node) {
    if (visited[node])
        return ;

    visited[node] = 1;

    for (int i = 1; i <= n; ++i) {
        if (graph[node][i])
            dfs(i);
    }

    ordering.push_back(node);
}

int main(int argc, char const *argv[]) {
    while (cin >> n >> m && (n || m)) {
        int x, y;
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        ordering.clear();

        while (m--) {
            cin >> x >> y;
            graph[x][y] = 1;
        }

        for (int i = 1; i <= n; i++)
            dfs(i);

        reverse(ordering.begin(), ordering.end());

        cout << ordering[0];

        for (int i = 1; i < ordering.size(); ++i) {
            cout << " " << ordering[i];
        }

        cout << endl;
    }
    return 0;
}