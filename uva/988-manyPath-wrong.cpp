// I don't think this wrong version is wrong
// although it failed uva's test
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

std::vector<int> v;
std::vector<int> death;
char graph[15000][15000];
char visited[15000];
int dp[15000];
int n;

void dfs(int node) {
    if (visited[node])
        return ;
    visited[node] = 1;

    for (int i = 0; i < n; ++i) {
        if (graph[node][i])
            dfs(i);
    }

    v.push_back(node);
}

int main(int argc, char const *argv[]) {
    freopen("988-graph.txt", "r", stdin);
    int t = 0, e, j;

    while (cin >> n) {
        if (t++)
            cout << endl;
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        memset(dp, 0, sizeof(dp));

        v.clear();
        death.clear();

        for (int i = 0; i < n; ++i) {
            cin >> e;
            if (!e)
                death.push_back(i);
            while (e--)  {
                cin >> j;
                graph[i][j] = 1;
            }
        }

        for (int i = 0; i < n; i++)
            dfs(i);

        reverse(v.begin(), v.end());

        dp[0] = 1;

        for (int i = 0; i < v.size(); ++i) {
            int u = v[i];
            for (int j = 0; j < n; ++j) {
                if (graph[u][j])
                    dp[j] += dp[u];
            }
        }

        int sum = 0;

        for (int i = 0; i < death.size(); i++)
            sum += dp[death[i]];

        cout << sum << endl;
    }

    return 0;
}