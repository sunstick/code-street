#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
std::vector<vector<int> > adjacentList;
std::vector<int> dfs_num;
std::vector<int> dfs_low;
std::vector<int> in;
std::vector<int> vis;
std::vector<int> s;
int dfs_counter;
int total;

void initialize() {
    adjacentList.clear();
    adjacentList.assign(n, vector<int>());
    dfs_num.clear();
    dfs_num.assign(n, 0);
    dfs_low.clear();
    dfs_low.assign(n, 0);
    in.clear();
    in.assign(n, 0);
    vis.clear();
    vis.assign(n, 0);
    s.clear();
    dfs_counter = total = 0;
}

void dfs_scc(int u) {
    dfs_low[u] = dfs_num[u] = ++dfs_counter;
    s.push_back(u);
    vis[u] = 1;

    for (int j = 0; j < adjacentList[u].size(); j++) {
        int v = adjacentList[u][j];

        if (!vis[v])                                // never been visited
            dfs_scc(v);
        if (dfs_num[v] != 0) {                      // have been visited and not "released"
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            in[v]--;
        }

    }

    if (dfs_low[u] == dfs_num[u]) {                 // root of scc
        bool flag = true;

        while (1) {
            int v = s.back(); s.pop_back();
            dfs_num[v] = 0;                         // crucial step, "release" node v, don't consider v for updating
            if (in[v])
                flag = false;
            if (u == v)
                break;
        }

        if (flag)
            total++;
    }
}


int main(int argc, char const *argv[]) {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        initialize();
        while (m--) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;

            adjacentList[x].push_back(y);
            in[y]++;
        }

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs_scc(i);
            }
        }

        cout << total << endl;
    }

    return 0;
}