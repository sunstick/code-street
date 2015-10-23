#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class Prioritize {
public:
    int operator() ( const int &p1,
                     const int &p2 ) {
        return p1 > p2;
    }
};

int graph[110][110];
int incoming_edge_count[110];
int n, m;
std::vector<string> drinks;
std::map<string, int> drinks_map;

void initialize() {
    memset(graph, 0, sizeof(graph));
    memset(incoming_edge_count, 0, sizeof(incoming_edge_count));

    drinks.clear();
    drinks_map.clear();
}

void bfs() {
    priority_queue<int, vector<int>, Prioritize > pq;
    for (int i = 0; i < n; i++) {
        if (incoming_edge_count[i] == 0)
            pq.push(i);
    }

    while (!pq.empty()) {
        int node = pq.top();
        pq.pop();

        cout << " " << drinks[node];

        for (int i = 0; i < n; ++i) {
            if (graph[node][i]) {
                incoming_edge_count[i]--;
                if (incoming_edge_count[i] == 0)
                    pq.push(i);
            }
        }
    }
}


int main(int argc, char const *argv[]) {
    int cases = 0;
    while (cin >> n) {
        initialize();
        cases++;

        int temp = n;
        while (n-- ) {
            string d;
            cin >> d;
            drinks.push_back(d);
            drinks_map[d] = drinks.size() - 1;
        }
        n = temp;

        cin >> m;

        while (m--) {
            string d1, d2;
            cin >> d1 >> d2;
            if (!graph[drinks_map[d1]][drinks_map[d2]]) {
                graph[drinks_map[d1]][drinks_map[d2]] = 1;
                incoming_edge_count[drinks_map[d2]]++;
            }
        }

        cout << "Case #" << cases << ": Dilbert should drink beverages in this order:";
        bfs();

        cout << ".\n\n";

    }
    return 0;
}