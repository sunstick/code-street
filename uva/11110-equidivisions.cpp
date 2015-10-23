#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int total;
int graph[110][110];
int n;

void flood_fill(int x, int y, int color) {
    if (graph[x][y] != color)
        return ;
    graph[x][y] = n;
    total ++;
    flood_fill(x + 1, y, color);
    flood_fill(x - 1, y, color);
    flood_fill(x, y + 1, color);
    flood_fill(x, y - 1, color);
}


int main(int argc, char const *argv[]) {
    while (cin >> n && n) {
        getchar();
        memset(graph, 0, sizeof(graph));
        int x, y;
        // deal with input
        bool flag = true;
        for (int i = 1; i < n; ++i) {
            string line;
            getline(cin, line);
            stringstream ss(line);


            while (ss >> x >> y)
                graph[x][y] = i;

            // is good ?
            if (flag) {
                total = 0;
                flood_fill(x, y, i);
                if (total != n)
                    flag = false;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i + 1][j + 1] == 0) {
                    x = i + 1;
                    y = j + 1;
                    graph[i + 1][j + 1] = -1;
                }
            }
        }

        if (flag) {
            total = 0;
            flood_fill(x, y, -1);
            if (total != n)
                flag = false;
        }

        if (flag)
            cout << "good" << endl;
        else
            cout << "wrong" << endl;
    }
    return 0;
}