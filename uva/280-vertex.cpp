#include <iostream>
#include <cstring>

using namespace std;

int graph[110][110];
int vis[110];
int total;
int n;

void dfs(int node) {
    for (int i = 1; i <= n; ++i) {
        if (graph[node][i] && !vis[i]) {
            vis[i] = 1;
            total++;
            dfs(i);
        }
    }
}

int main(int argc, char const *argv[]) {
    while (true) {

        if (cin >> n && n) {
            memset(graph, 0, sizeof(graph));

            int m;
            while (true) {
                if (cin >> m && m) {
                    int t;
                    while (cin >> t && t) {
                        graph[m][t] = 1;
                    }
                } else
                    break;
            }

            cin >> m;
            //cout << "   " << m << "    " << endl;
            while (m-- ) {
                int node;
                cin >> node;
                //cout << "   " << node << "    " << endl;
                memset(vis, 0, sizeof(vis));
                total = 0;

                dfs(node);

                cout << n - total;

                for (int i = 1; i <= n; ++i) {
                    if (!vis[i])
                        cout << " " << i;
                }
                cout << endl;
            }


        } else
            break;

    }
    return 0;
}