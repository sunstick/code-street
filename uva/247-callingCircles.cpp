#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#define NUM_NODES 30

using namespace std;

int n;                              // actual number of nodes
int m;
int dfs_counter;                    // initial value 0
int scc_counter;                    // initial value 0
int vis[NUM_NODES];                 // 0 for unvisited, 1 for visited
int graph[NUM_NODES][NUM_NODES];    // adjacent matrix of graph, 0 & 1
int dfs_num[NUM_NODES];             // initial value 0
int dfs_low[NUM_NODES];             // initial value 0
vector<int> s;                      // a stack to store scc
vector<string> name;
map<string, int> ofname;


void initialize() {
    memset(graph, 0, sizeof(graph));
    memset(dfs_low, 0, sizeof(dfs_low));
    memset(dfs_num, 0, sizeof(dfs_num));
    memset(vis, 0, sizeof(vis));
    s.clear();
    name.clear();
    ofname.clear();
    dfs_counter = scc_counter = 0;
}

void dfs_scc(int u) {
    dfs_low[u] = dfs_num[u] = ++dfs_counter;
    s.push_back(u);
    vis[u] = 1;

    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {
            if (!vis[v])
                dfs_scc(v);
            if (dfs_num[v] != 0)
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }

    if (dfs_low[u] == dfs_num[u]) {                 // root of scc

        while (1) {
            int v = s.back(); s.pop_back();


            dfs_num[v] = 0;                         // crucial step
            if (u == v) {
                cout << name[v] << endl;
                break;
            } else {
                cout << name[v] << ", ";
            }

        }

    }
}

int main(int argc, char const *argv[]) {
    int dataset = 0;
    while (cin >> n >> m && (n || m)) {
        if (dataset)
            cout << endl;
        initialize();
        dataset++;
        while (m--) {
            string name1;
            string name2;
            cin >> name1 >> name2;

            if (!ofname.count(name1)) {
                name.push_back(name1);
                ofname[name1] = name.size() - 1;
            }

            if (!ofname.count(name2)) {
                name.push_back(name2);
                ofname[name2] = name.size() - 1;
            }

            graph[ofname[name1]][ofname[name2]] = 1;
        }

        cout << "Calling circles for data set " << dataset << ":" << endl;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs_scc(i);
            }
        }
    }

    return 0;
}