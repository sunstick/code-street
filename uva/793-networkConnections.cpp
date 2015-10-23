#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>

using namespace std;

int father[100000];
int rank[100000];

void make_set(int x) {
    father[x] = x;
    rank[x] = 0;
}

int find_set(int x) {
    if (x != father[x])
        father[x] = find_set(father[x]);
    return father[x];
}

void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y)
        return ;
    if (rank[x] > rank[y]) {
        father[y] = x;
    } else {
        if (rank[x] == rank[y])
            rank[y]++;
        father[x] = y;
    }
}


int main() {
    int n, m, x, y, n1 = 0, n2 = 0;
    char cq;
    string line;

    cin >> n;
    while (n-- > 0) {
        cin >> m;
        getchar();
        for (int i = 1; i <= m; i++)
            make_set(i);
        n1 = n2 = 0;

        while (getline(cin, line) && line != "") {
            stringstream ss;
            ss << line;
            ss >> cq;
            ss >> x;
            ss >> y;

            if (cq == 'c')
                union_set(x, y);
            else {
                if (find_set(x) == find_set(y))
                    n1++;
                else
                    n2++;
            }
        }

        cout << n1 << "," << n2 << endl;
        if (n)
            cout << endl;
    }
    return 0;
}
