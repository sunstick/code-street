#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

int graph[6][6];
bool vis[6][6];

using namespace std;

void draw(int n, int node, string &str) {
    if (n == 16) {
        cout << str << endl;
        return ;
    }

    for (int i = 1; i <= 5; i++) {
        if (graph[node][i] && !vis[node][i] && !vis[i][node]) {
            vis[node][i] = 1;
            vis[i][node] = 1;
            char ii = (char) (i + '0');
            str += ii;
            draw(n + 2, i, str);
            str.erase(str.size() - 1, 1);
            vis[node][i] = 0;
            vis[i][node] = 0;
        }
    }
}

int main() {
    memset(vis, 0, sizeof(vis));
    memset(graph, 0, sizeof(graph));
    graph[1][2] = 1;
    graph[1][5] = 1;
    graph[1][3] = 1;

    graph[2][1] = 1;
    graph[2][5] = 1;
    graph[2][3] = 1;

    graph[3][1] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;
    graph[3][5] = 1;

    graph[4][3] = 1;
    graph[4][5] = 1;

    graph[5][1] = 1;
    graph[5][2] = 1;
    graph[5][3] = 1;
    graph[5][4] = 1;
    int ne = 8;
    string str = "1";
    draw(0, 1, str);
    return 0;
}

